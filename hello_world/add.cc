#include <iostream>
using namespace std;

int main() {
	int age = 0;

	cout << "Please give me your age: ";
	cin >> age;
	if (age >= 16)
		cout << "You can drive a car!" << endl;
	if (age >= 18)
		cout << "You can smoke tovbacco!" << endl;
	if (age >= 21)
		cout << "You can drink alcohol!" << endl;
	else
		cout << "You are too young to have any fun!" << endl;

	return 0;
}
