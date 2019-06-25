#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin,s);
	for (size_t i = 0; i < s.size(); i++) {
		char c = toupper(s.at(i));
		if (c == 'A') {
			cout << '4';
		}
		else if (c == 'O') {
			cout << '0';
		}
		else if (c == 'B') {
			cout << '8';
		}
		else if (c == 'S') {
			cout << '5';
		}
		else if (c == 'T') {
			cout << '7';
		}
		else if (c == 'E') {
			cout << '3';
		}
		else if (c == 'L') {
			cout << '1';
		}
		else
			cout << c;
	}
	cout << endl;
}
