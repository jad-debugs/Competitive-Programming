#include <iostream>
using namespace std;

void solve(int n) {
	for(int i = n; i > 0; i--)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		solve(n);
	}
	return EXIT_SUCCESS;
}