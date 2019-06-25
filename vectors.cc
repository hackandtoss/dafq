#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> nums(20);
	unsigned int n = nums.size();
	double sum = 0;
	for (unsigned int  i = 0; i < n; i++cout) {
		cout << "Give me an int.\n";
		cin >> nums.at(i);
	}
	for (unsigned int j = 0; j < n; j++) {
		sum += nums.at(j);
	}
	cout << "Average: " << sum / nums.size() << endl;
}
