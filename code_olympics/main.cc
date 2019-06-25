#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

//Only write code where it says YOU:
//Each event involves you writing only a SINGLE line of code. (Or thereabouts.)

//This function should return (three times a) plus (four times b)
int first(int a, int b) {
	//YOU:
	return (3 * a) + (4 * b);
}

//This function should set c to be (three times a) plus (four times b)
//  c is a "call by reference" output parameter
void second(int a, int b, int &c) {
	//YOU:
	c = (3 * a) + (4 * b);
}

//This function will sum up all the values in vec and return the result
//For example, vec = {0,1,2,3,4} would return 10.
int third(vector<int> vec) {
	int sum = 0;
	for (unsigned int i = 0; i < vec.size(); i++) {
		//YOU:
		sum += vec.at(i);
	}
	return sum;
}

//This function will count the number of odd numbers in vec, and return the count
//For example, vec = {1,2,3,4,5} would return 3, because there is a 1, a 3, and a 5.
int fourth(vector<int> vec) {
	int count = 0;
	for (unsigned int i = 0; i < vec.size(); i++) {
		//YOU:
		if (vec.at(i) % 2 != 0)
			count++;
	}
	return count;
}

//5th event: Write a function that will make a vector of size x,
// which will be set to be {0,1,2,3,..,x-1}
vector<int> fifth(unsigned int x) {
	vector<int> retval;
	for (size_t i = 0; i < x; i++) {
		retval.push_back(i);
	}
	//YOU: Write the code here

	return retval;
}

//========================================
//DON'T MODIFY ANY CODE BELOW THIS POINT
//========================================
int main() {
	cout << "Welcome to the Spring Code Olympics!\n";
	cout << "Please enter which event you wish to compete in (first, second, third, fourth, fifth): \n";
	string input;
	cin >> input;
	if (input == "1" or input == "first") {
		cout << "Please type two numbers:\n";
		int a, b;
		cin >> a >> b;
		if (!cin) return -1;
		cout << "The result is: " << first(a, b) << endl;
	} else if (input == "2" or input == "second") {
		cout << "Please type two numbers:\n";
		int a, b, c;
		cin >> a >> b;
		if (!cin) return -1;
		second(a, b, c);
		cout << "The result is: " << c << endl;
	} else if (input == "3" or input == "third") {
		cout << "Please input numbers (0 to end):\n";
		int a;
		vector <int> vec;
		while (true) {
			cin >> a;
			if (!cin) break;
			if (a == 0) break;
			vec.push_back(a);
		}
		cout << "The sum of all the numbers is: " << third(vec) << endl;
	} else if (input == "4" or input == "fourth") {
		cout << "Please input numbers (0 to end):\n";
		int a;
		vector <int> vec;
		while (true) {
			cin >> a;
			if (!cin) break;
			if (a == 0) break;
			vec.push_back(a);
		}
		cout << "The number of odd numbers typed in is: " << fourth(vec) << endl;
	} else if (input == "5" or input == "fifth") {
		cout << "Please input an integer:\n";
		int x;
		cin >> x;
		if (!cin) exit(1);
		vector<int> vec = fifth(x);
		for (int i : vec) cout << i << " ";
		cout << endl;
	} else {
		cout << "Bad choice, you are hereby disqualified from the Code Olympics!\n";
	}
	return 0;
}
