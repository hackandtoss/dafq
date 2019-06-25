#include <iostream>
#include <vector>
using namespace std;

void clamp(long long int &min, long long int &max, long long int &x) {
	if (x < min)
		x = min;
	else
		x = max;
}

int main() {
	long long int a = 0;
	long long int b = 1;
	long long int c = 2;
	clamp(a, b , c);
	cout << c << endl;
}
