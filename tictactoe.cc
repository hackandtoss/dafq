#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 3;

void print_array(string arr[SIZE][SIZE]) {
	for (size_t i = 0; i < SIZE; i++) {
		cout << "-------------\n";
		cout << "| ";
		for (size_t j = 0; j < SIZE; j++) {
			cout << arr[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "-------------\n";
}

int main() {
	string board[SIZE][SIZE];
	for (size_t i = 0; i < SIZE; i++) {
		for (size_t j = 0; j < SIZE; j++) {
			board[i][j] = " ";
		}
	}
	print_array(board);
	while (true) {
		cout << "Please enter x and y of your move:\n";
		int x,y;
		cin >> x >> y;
		//Vet input
		if (!cin) exit(0);
		if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) break;
		cout << "Please enter your symbol:\n";
		string s;
		cin >> s;
		board[x][y] = s;
		print_array(board);
	}
}
