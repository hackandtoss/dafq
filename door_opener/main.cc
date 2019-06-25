#include <iostream>
#include <ctime>
#include <csignal>
using namespace std;

clock_t start; //Time that the stopwatch was started
void wait_three_seconds() {
	start = clock(); //Start the stopwatch
	while ((clock() - start) / CLOCKS_PER_SEC < 3)
		; //Do nothing until three seconds have gone since the start
}

const int CLOSED = 0;
const int OPENING = 1;
const int OPEN = 2;
const int CLOSING = 3;
int state = CLOSED;
string input;

void signal_handler(int signal) {
	//cout << "Interrupt Received: " << signal << endl;
	start = clock(); //Reset the starting time on the stopwatch
	if (signal == SIGINT) {
		state = OPENING;
		input = "person";
	}
	if (signal == SIGTSTP) {
		state = OPENING;
		input = "fire";
	}
}

int main() {
	signal(SIGINT, signal_handler); //Catch ctrl-c
	signal(SIGTSTP, signal_handler); //Catch ctrl-z
	//signal(SIGINT,SIG_DFL); //Reset the ctrl-c handler to the default
	;
	while (cin) {
		cin >> input; //Read a command
		if (input == "quit") break;
		//Handle state transitions here
		while (true) {
			state += 1;
			state %= 4;
			switch (state) {
			case CLOSED :
				cout << "Closed!\n";
				break;
			case OPENING :
				cout << "Opening...\n";
				wait_three_seconds();
				break;
			case OPEN :
				cout << "Open " << input << " walks through.\n";
				wait_three_seconds();
				break;
			default :
				cout << "Closing...\n";
				wait_three_seconds();
				break;
			}
			if (state == 0) break;
		}
	}
}
