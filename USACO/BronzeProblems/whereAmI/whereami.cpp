/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int main () {
	

	freopen("whereami.in","r",stdin);
 	freopen("whereami.out","w",stdout);

	int n;
	bool found = true;
	string s;

	cin >> n;
	int ans = n/2+1;
	cin >> s;

 	set<string> x;
 	
 	for(int i = 1; i <= n; i++) {
 		found = true;
 		for(int j = 0; j <= n-i; j++) {
 			if(x.count(s.substr(j, i)) == 1) {
 				found = false;
 				break;
 			}
 			x.insert(s.substr(j,i));
 		}
 		if(found) {
 			ans = i;
 			break;
 		}
 	}
 	cout << ans;
	return 0;
}
