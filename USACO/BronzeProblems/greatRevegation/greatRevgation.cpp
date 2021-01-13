/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "revegetate") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

	int n, cows;
	cin >> n >> cows;

	int arr[cows][2];

	for(int i = 0; i < cows; i++) {
		for(int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	int ans[n];

	for(int i = 0; i < n; i++)
		ans[i] = i+1;

	bool works = true;
	do {
		works = true;
		for(int i = 0; i < cows; i++) {
			if(ans[arr[i][0]-1] == ans[arr[i][1]-1]) {
				works = false;
				break;
			}
		}
	} while(next_permutation(ans, ans + n));

	if(works) {
		for(int i = 0; i < n; i++)
			cout << ans[i];
	}
	return 0;
}
