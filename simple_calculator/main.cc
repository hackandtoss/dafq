

//GL;HF
/*
Homework - In your "simple_calculator" directory

You will write a program that will enable a user to do simple mathematical calculations.

You must do it from scratch - don't forget the magic!

It will need to do the following:

1. Prompt the user with the following string: "1) addition 2) subtraction 3) multiplication 4) division: "

2. Input their choice into an integer variable named whatever you want.

3. Prompt them with the following string: "Please enter two numbers: "

4. Input two integers from the keyboard into two variables called whatever you want.

5. Do the math of their choice (i.e. if they typed 2 8 5, you will subtract (choice 2) 8 and 5).

6. Output the result to the screen and quit.

BONUS POINTS!

7. Validate the input - NO DIVISION BY ZERO (or modulus by zero) and check to
make sure they typed a number between 1 and 4 for the operator.

If they gave a bad input: output "BAD INPUT!" and quit.

8. Add modulus as option #5. Don't change the prompt (in #1), it will be a
secret easter egg. Also modify #7 so it doesn't output BAD INPUT! on a 5.
*/

#include <iostream>
using namespace std;

int main() {

	int choice = 0;
	int x = 0;
	int y = 0;
	int z = 0;

	// Get opperation to be used from user.
	cout <<  "1) addition 2) subtraction 3) multiplication 4) division: " << endl;
	cin  >> choice;

	// Only should be choices 1 - 5.
	if (choice < 1 || choice > 5) {
		cout << "BAD INPUT!" << endl;
		return 1;
	}

	// Get numbers from user.
	cout << "Please enter two numbers: " << endl;
	cin >> x;
	cin >> y;

	// Check divide by zero.
	if (choice > 3 && y == 0) {
		cout << "BAD INPUT!" << endl;
		return 1;
	}
	// # maps to opperation.
	if (choice == 1) {
		z = x + y;
		cout << z << endl;
	} else if (choice == 2) {
		z = x - y;
		cout << z << endl;
	} else if (choice == 3) {
		z = x * y;
		cout << z << endl;
	} else if (choice == 4) {
		z = x / y;
		cout << z << endl;
	} else {
		z = x % y;
		cout << z << endl;
	}

	return 0;
}
