#include <iostream>
using namespace std;

int solve(string binary)
{
	if(binary.size()%2)
		return -1;
	int off = 0;
	int on = 0;

	for(char ch : binary) {
		if(ch == '0')
			off++;
		if(ch == '1')
			on++;
	}
	if(on <= 0 || off <= 0)
		return -1;
	if(on > off) {
		return (binary.size()/2 - off);
	}
	else if (on < off){
		return (binary.size()/2 - on);
	}	
	return 0;
}

int main()
{
	// if odd, return -1
	// make number of 0 = to number of one

	int t; cin >> t;
	int arr[t];
	for(int i = 0; i < t; i++) {
		string word; cin >> word;
		arr[i] = solve(word);
	}

	for(int i = 0; i < t-1; i++)
		cout << arr[i] << "\n";
	cout << arr[t-1];
}