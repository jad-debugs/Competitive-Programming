#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	string str; cin >> str;
 
	if(str.size() < 7) {
		cout << "NO";
		return 0;
	}
 
	bool same = true;
	for(int i = 0; i < str.size() - 6; i++) {
		string word = str.substr(i,7);
		same = true;
		char check = word[0];
		for(char x : word) {
			if(check != x)
				same = false;
		}
		if(same) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return EXIT_SUCCESS;
}
