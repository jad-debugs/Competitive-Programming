/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "hps") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("hps");
	int n; cin >> n;

	int p1[n], p2[n], posPerm[] = {1, 2, 3};

	for(int i = 0; i < n; i++) {
		cin >> p1[i] >> p2[i];
	}

	int ans = 0;

	do {
    	int tmp = 0;
    	for(int i = 0; i < n; i++) {
    		if((p1[i] == posPerm[0] && p2[i] == posPerm[1]) || (p1[i] == posPerm[1] && p2[i] == posPerm[2]) || (p1[i] == posPerm[2] && p2[i] == posPerm[0]))
    			tmp++;
    	}
    	ans = max(ans, tmp);
  	} while (next_permutation(posPerm,posPerm+3));

  	cout << ans;
}
