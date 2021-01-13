#include <bits/stdc++.h>
using namespace std;

string solve(int x, int y, int k, int maxN)
{
	// find avg, if avg is fraction, return false
	// if max(x, y) - avg %k == 0, if yes, return true
	float avg = (x+y)/2.0;

	if((x+y)/2 != avg)
		return "No";

	int diffFromAvg = abs(x - avg);

	if(diffFromAvg%k == 0)
		return "Yes";
	return "No";
}

int main()
{
	int t; cin >> t;
	int tmpT = t;
	string arr[t];
	int i = 0;
	for(int i = 0; i < t; i++) {
		int x, y, k, maxN; cin >> x >> y >> k >> maxN;
		arr[i] = solve(x, y, k, maxN);
	}

	for(int i = 0; i < t-1; i++) {
		cout << arr[i] << endl;
	}
	cout << arr[tmpT-1];
	return 0;
}
