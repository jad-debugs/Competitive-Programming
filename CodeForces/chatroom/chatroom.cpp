#include <iostream>
using namespace std;

int searchChar(char x, int start, string word) {
	for(int i = start; i < word.size(); i++) {
		if(word[i] == x) {
			return i+1;
		}
	}
	return 0;
}

int main()
{
	string s; cin >> s;

	int idx;

	for(int i = 0; i < s.size(); i++) {
		if((idx = searchChar('h', i, s)) != 0)
			break;
	}
	if(idx) {
		if( (idx = searchChar('e', idx, s)) != 0) {
			if( (idx = searchChar('l', idx, s)) != 0) {
				if( (idx = searchChar('l', idx, s)) != 0) {
					if( (idx = searchChar('o', idx, s)) != 0) {
						cout << "YES";
						return 0;
					}
					else {cout << "NO"; return 0;}
				}
				else {cout << "NO"; return 0;}
			}
			else {cout << "NO"; return 0;}
		}
		else {cout << "NO"; return 0;}
	}
	else {cout << "NO"; return 0;}

	return EXIT_SUCCESS;
} 