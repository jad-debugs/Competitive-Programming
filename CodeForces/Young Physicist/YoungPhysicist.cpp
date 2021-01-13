#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int aT = 0, bT = 0, cT = 0;
	while(n--) {
		int a, b, c;
		cin >> a >> b >> c;

		aT += a; bT += b; cT += c;
	}

	if(!aT && !bT && !cT)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}	