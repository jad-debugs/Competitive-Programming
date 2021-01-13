/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("cowtip");

	int n; cin >> n;

	char arr[n][n];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			if(arr[i][j] == '1') {
				ans++;
				for(int a = 0; a <= i ; a++) {
					for(int b = 0; b <= j; b++) {
						if(arr[a][b] == '0')
							arr[a][b] = '1';
						else
							arr[a][b] = '0';
					}
				}
			}
		}
	}
	cout << ans;
	return EXIT_SUCCESS;
}
