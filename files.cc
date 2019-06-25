#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<int> scores = {7, 7, 7, 42};
	cout << "what do you want to write to?\n";
	string s;
	cin >> s;
	ofstream out_file(s);

	for (size_t i = 0; i < scores.size(); i++) {
		out_file << scores.at(i)  << endl;
	}
}

