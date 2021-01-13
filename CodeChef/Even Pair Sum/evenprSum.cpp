#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t; cin >> t;

	vector<long long> pairs;
	while(t--) {
		long long a, b, total; cin >> a >> b;

		long long evensA, evensB, oddsA, oddsB;

		evensA = a/2;
		oddsA = a - evensA;
		evensB = b/2;
		oddsB = b - evensB;

		total = a*b - evensA*oddsB - evensB*oddsA;

		pairs.push_back(total);
	}
	for(long long i = 0; i < pairs.size(); i++)
		cout << pairs[i] << "\n";
}
