#include <iostream>
using namespace std;

int main() {

	int x = 0;
	int y = 0;
	int c = 0;
	// Array of strings makes it easier for itterating over, when translating.
	string s[] = {"ling", "yi", "er", "san", "se", "wu", "liu", "qi", "ba", "jiu", "shi"};

	// Max range
	cout << "Please enter a number that you want to count up to in Mandarin. ";
	cin >> y;

	// Check for valid input
	if (!cin || y > 99 || y < 0) {
		cout << endl;
		return 1;
	}

	// Start
	cout << "Please enter what number to start with: ";
	cin >> x;

	// Check for valid input
	if (!cin || x > 99 || x < 0) {
		cout << endl;
		return 1;
	}

	// Step size
	cout << "What step size do you want to use?\n";
	cin >> c;

	// Check for valid input
	if (!cin || c > 99 || c < 1) {
		cout << endl;
		return 1;
	}

	// Itterate from start to and including end. Increasing by the count size.
	for (int i = x; i <= y; i += c) {
		if (i < 10) {
			cout << i << " " << s[i] << endl;
		} else if (i < 20) {
			cout << i << " " << s[10];
			if (i % 10 != 0) {
				cout << " " << s[i % 10];
			}
			cout << endl;
		} else {
			// i / 10 gets the first digit. i % 10 gets the last.
			cout << i << " " << s[i / 10] << " " << s[10];
			if (i % 10 != 0) {
				cout << " " << s[i % 10];
			}
			cout << endl;
		}
	}
	return 0;
}