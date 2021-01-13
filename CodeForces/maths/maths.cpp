#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{	
	string word; cin >> word;
	
	vector<int> v;

	for(char x: word) {
		if(isdigit(x)) {
			v.push_back((int)x - (int)'0');					
		}	
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size()-1; i++) {
		cout << v[i] << "+";
	}
	cout << v[v.size()-1];

	return 0;

}
	
	
