#include <iostream>
using namespace std;

int main () {
	string n;
	cin >> n;
	int len = n.length();
	cout << n[len-2];

	return 0;
}