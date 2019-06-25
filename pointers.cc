#include <iostream>
using namespace std;

int main() {
	int x = 40;
	// * is dereffernce opperator
	// & is address of
	// new = allocates memory.
	// delete = delete allocated mem
	int *ptr = &x;
	*ptr = 42;

	cout << "x = " << x << endl;
	cout << "ptr = " << ptr << endl;

	return 0;

}
