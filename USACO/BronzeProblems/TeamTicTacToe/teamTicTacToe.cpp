#include <bits/stdc++.h>
using namespace std;

string sortString(string &str) 
{ 
   sort(str.begin(), str.end()); 
   return str;
} 

int main()
{
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	char arr[3][3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	
	set<string> doubleWinners;

	set<char> singleWinners;

	set<char> set;

	

	// rows

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			set.insert(arr[i][j]);
		}
		if(set.size() == 2) {
			string tmp = "";
			for(auto x : set) {
				tmp += x;
			}
			tmp = sortString(tmp);
			doubleWinners.insert(tmp);
		}
		else if(set.size() == 1) {
			char letter;
			for(auto x : set) {
				letter = x;
			}
			singleWinners.insert(letter);
		}
		set.clear();
	}

	// columns

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			set.insert(arr[j][i]);
		}
		if(set.size() == 2) {
			string tmp = "";
			for(auto x : set) {
				tmp += x;
			}
			tmp = sortString(tmp);
			doubleWinners.insert(tmp);
		}
		else if(set.size() == 1) {
			char letter;
			for(auto x : set) {
				letter = x;
			}
			singleWinners.insert(letter);
		}
		set.clear();
	}

	//diagnols

	set.insert(arr[0][2]); set.insert(arr[1][1]); set.insert(arr[2][0]);

	if(set.size() == 2) {
		string tmp = "";
		for(auto x : set) {
			tmp += x;
		}
		tmp = sortString(tmp);
		doubleWinners.insert(tmp);
	}
	else if(set.size() == 1) {
		char letter;
		for(auto x : set) {
			letter = x;
		}
		singleWinners.insert(letter);
	}
	set.clear();

	set.insert(arr[0][0]); set.insert(arr[1][1]); set.insert(arr[2][2]);

	if(set.size() == 2) {
		string tmp = "";
		for(auto x : set) {
			tmp += x;
		}
		tmp = sortString(tmp);
		doubleWinners.insert(tmp);
	}
	else if(set.size() == 1) {
		char letter;
		for(auto x : set) {
			letter = x;
		}
		singleWinners.insert(letter);
	}
	set.clear();

	cout << singleWinners.size() << endl << doubleWinners.size();

	return EXIT_SUCCESS;
}