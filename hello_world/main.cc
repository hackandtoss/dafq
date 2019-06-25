#include <iostream>
using namespace std;

// typedef  char * string;

int main() {

	int x = 0;
	do {
		cout << "Please enter X:" << endl;
		cin >> x;
	} while (x < 0 || x > 20);

	cout << x << endl;

	// string even = "Even!";
	// string odd = "odd";
	int y = 3;
	int z = x + y;

	cout << z << endl;

	z++;
	cout << z << endl;
	z = z * z % y;
	cout << z << endl;
	for (int i = 0; i < 9; i++) {
		z = z * 2;
		cout << z << endl;
		z++;
	}
	x = x * z;
	if (x % 2 == 0) {
		cout << "Even!" << endl;
	} else {
		cout << "Odd!" << endl;
	}

	return 0;
}
