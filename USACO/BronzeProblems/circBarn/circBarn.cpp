#include <bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	int n; cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int distWalked = n*n*100;

	for(int rm_num = 0; rm_num < n; rm_num++) {
		int tmpDist = 0;
		for(int dist = 0; dist < n; dist++) {
			tmpDist += dist*arr[(rm_num+dist)%n];
		}
		distWalked = min(tmpDist, distWalked);
	}

	cout << distWalked;

	return EXIT_SUCCESS;
}

