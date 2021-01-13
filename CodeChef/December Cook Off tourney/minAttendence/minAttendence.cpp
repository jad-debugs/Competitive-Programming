#include <iostream>
using namespace std;

string solve(string s) {
	int zeros = 0;
	for(char x: s) {
		if(x == '0')
			zeros++;
	}
	if(zeros <= 30)
		return "YES";
	return "NO";
}

int main()
{
	int n; cin >> n;
	string arr[n];
	int i = 0;
	int tmpN = n;
	while(tmpN--) {
		int t; cin >> t;
		string word; cin >> word;
		arr[i] = solve(word);
		i++;
	}
	int size;
	for(int j = 0; j < n-1; j++) {
		cout << arr[j] << "\n";
	}

	cout << arr[n-1];

	return 0;
}