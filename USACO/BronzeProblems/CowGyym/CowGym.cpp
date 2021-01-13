#include <bits/stdc++.h>
using namespace std;

int isConst(int a, int b, vector<vector<int>> arr);


int main()
{
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int k, n; cin >> k >> n;

	vector<vector<int>> arr;

	for(int i = 0; i < k; i++) {
		vector<int> a;
		for(int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			a.push_back(tmp);
		}
		arr.push_back(a);
	}
	int pairs = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				continue;
			}
			pairs += isConst(i, j, arr);
		}
	}

	cout << pairs; 
	return EXIT_SUCCESS;

}

int isConst(int a, int b, vector<vector<int>> arr)
{
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[i].size(); j++) {
			if(arr[i][j] == a)
				break;
			else if(arr[i][j] == b)
				return 0;
		}
	}
	return 1;
}