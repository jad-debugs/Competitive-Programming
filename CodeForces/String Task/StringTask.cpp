#include <iostream>
#include <string>
#include <algorithm> // tolower
using namespace std;

int main()
{
	string word;
	cin >> word;

	transform(word.begin(),word.end(), word.begin(), ::tolower);

	for(char x : word) {
		if(x != 'a' && x != 'o' && x != 'y' && x != 'e' && x != 'u' && x != 'i')
			cout << '.' << x;
	}

	return EXIT_SUCCESS;
}