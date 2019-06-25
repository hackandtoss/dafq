// #include <doalarm>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 10;
const int DESTROYER = 2;
const int CRUSER = 3;
const int SUB = 3;
const int BATTLESHIP = 4;
const int AIRCRAFT_CARRIER = 5;
const vector<string> SHIP_NAME = { "DESTROYER", "CRUSER", "SUB", "BATTLESHIP", "AIRCRAFT CARRIER" };
const string HIT = "  *  ";
const string MISS = "  %  ";
const string BLANK = "  .  ";

void clear(int t);
void intro();
void print_grid(string s[][BOARD_SIZE], int n, int x);
void die();
void get_row(char &l, int &n);
void get_col(int &n);
void win();
void lose();

int main() {
	srand(time(0));

	// Ship health
	vector<int> health = { DESTROYER, CRUSER, SUB, BATTLESHIP, AIRCRAFT_CARRIER };

	// Chars of ship. If hit change char
	vector<string> ship_char = {"  D  ", "  C  ", "  S  ", "  B  ", "  A  "};
	int torpedoes = 40;
	int ships_remaining = health.size();

	// Timed intro sequence
	intro();

	// initializes board to 10x10 of dots
	string board[BOARD_SIZE][BOARD_SIZE];
	for (int col = 0; col < BOARD_SIZE; col++) {
		for (int row = 0; row < BOARD_SIZE; row++) {
			board[row][col] = BLANK;
		}
	}

	// Grid of bools set to false to check if there is a ship
	bool is_ship[BOARD_SIZE][BOARD_SIZE];
	for (int col = 0; col < BOARD_SIZE; col++) {
		for (int row = 0; row < BOARD_SIZE; row++) {
			is_ship[row][col] = false;
		}
	}

	bool ship_check = false;
	char c = 0;
	int row = 0;
	int col = 0;
	char dir = 0;

	/*
	 * Potential bug in getting last ship and assigning board[][] = char of ship
	 * and is_ship[][] = true
	 */

	// Itterate through ships and get coridinates from user plus ship direction
	for (size_t i = 0; i < health.size(); i++) {
		do {
			ship_check = false;
			c = 0;
			row = 0;
			col = 0;

			print_grid(board, torpedoes, ships_remaining);
			cout << "Ship number " << i + 1 << " is " << SHIP_NAME.at(i) << " it has a size of " << health.at(i) << endl;
			get_row(c, row);
			get_col(col);
			do {
				cout << "Please give me a direction (\'v\' for vertical \'h\' for horizontal.)\n";
				cin >> dir;
				if (!cin)
					die();
				dir = tolower(dir);
				cout << "dir is " << dir << endl;
			} while (dir != 'v' && dir != 'h');

			/*
			 * 'v' goes from the location where it is at down the distance of the ship.
			 * If a ship is at the bottom the ship must be placed upward so starting
			 * from the spot the user chose minus the ship size itterating the size of
			 * the ship should end at the location the user gave, checking all the possible
			 * ship locations.
			 * Simular for 'h'.
			 */

			if (dir == 'v' && row <= BOARD_SIZE - health.at(i)) {
				for (int j = 0; j < health.at(i); j++) {
					if (is_ship[row + j][col] == true) {
						ship_check = true;
					}
				}
			} else if (dir == 'h' && col <= BOARD_SIZE - health.at(i)) {
				for (int j = 0; j < health.at(i); j++) {
					if (is_ship[row][col + j] == true)
						ship_check = true;
				}
			} else
				ship_check = true;
			if (dir == 'v' && row <= BOARD_SIZE - health.at(i) && ship_check == false) {
				for (int j = 0; j < health.at(i); j++) {
					is_ship[row + j][col] = true;
					board[row + j][col] = ship_char.at(i);
				}
			}
			if (dir == 'h' && col <= BOARD_SIZE - health.at(i) && ship_check == false) {
				for (int j = 0; j < health.at(i); j++) {
					is_ship[row][col + j] = true;
					board[row][col + j] = ship_char.at(i);
				}
			}
			print_grid(board, torpedoes, ships_remaining);
		} while (ship_check == true);
	}

	/*
	 * Hits Misses and sinking of the ships.
	 * If torpedos == 0 or ships_remaining  == 0 game over.
	 * Torpedos == 0 means no torpedos left.
	 * Ships_remaining == 0 means all ships are sunk.
	 */

	while (ships_remaining > 0 && torpedoes > 0) {
		c = 0;
		row = 0;
		col = 0;
		print_grid(board, torpedoes, ships_remaining);
		get_row(c, row);
		get_col(col);
		if (is_ship[row][col] == true) {
			for (size_t i = 0; i < health.size(); i++) {
				if (board[row][col] == ship_char.at(i)) {
					board[row][col] = HIT;
					cout << "Hit!\n";
					health.at(i)--;
					if (health.at(i) <= 0) {
						ships_remaining--;
						cout << "You sunk my " << SHIP_NAME.at(i) << ". ships remaining: " << ships_remaining << endl;
					}
				}
			}
		} else if (board[row][col] == HIT)
			cout << "Nice job you hit a spot already hit!\n";
		else {
			cout << "Miss!\n";
			board[row][col] = MISS;
		}
		torpedoes--;
	}

	print_grid(board, torpedoes, ships_remaining);

	if (ships_remaining == 0)
		win();
	else
		lose();

	return 0;
}

// Waits t seconds then clears the screen
void clear(int t) {
	sleep(t);
	system("clear");
}

void die() {
	cout << "Bad input\n";
	exit(1);
}

// Timed sequence that introduces the game
void intro() {
	clear(0);
	cout << "Welcome to...\n";
	clear(2);
	system("figlet BATTLESLOOP");
	clear(2);
	cout << "brought to you by...\n";
	clear(2);
	system("figlet HACKSBRO");
	clear(3);
}

// Get string to be modified change  "  .  "" to new chars
void print_grid(string s[][BOARD_SIZE], int n, int x) {
	// Torpedoes
	clear(0);
	system("figlet BATTLESLOOP");
	cout << " " << endl;
	cout << "                        Torpedoes: " << n << endl;
	cout << "                  Ships remaining: " << x << endl;
	cout << " " << endl;
	char c = 'A';
	for (int i = 0; i < BOARD_SIZE + 1; i++) {
		for (int j = 0; j < BOARD_SIZE + 1; j++) {
			c = 'A' + i - 1;
			if (i == 0 && j == 0)
				cout << "      #  ";
			else if (i == 0)
				cout << "  " << j << "  ";
			else if (j == 0)
				cout << "      " << c << "  ";
			else
				cout << s[i - 1][j - 1];
		}
		cout << endl;
		cout << endl;
	}
}

// Get the row fro the user.
void get_row(char &l, int &n) {
	do {
		cout << "Please choose a row (A - J).\n";
		cin >> l;
		if (!cin)
			die();
		if (l > '9' || l < '0') {
			l = toupper(l);
			n = l - 'A';
		} else {
			n = l - '1';
		}
	} while (n < 0 || n > BOARD_SIZE - 1);
}

// get the column from the user.
void get_col(int &n) {
	do {
		cout << "Please choose a colulmn (1 - 10).\n";
		cin >> n;
		if (!cin)
			die();
		// Grid is printed out A - J and 1 - 10. col needs to be index 0
		n--;
	} while (n < 0 || n > BOARD_SIZE - 1);
}

// If you sink all of the ships
void win() {
	system("figlet WINNER");
	exit(0);
}

// If you ran out of torpedos.
void lose() {
	system("figlet GAME");
	system("figlet OVER");
	exit(0);
}
