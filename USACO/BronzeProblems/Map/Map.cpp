#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("citystate.in","r",stdin);
 	freopen("citystate.out","w",stdout);

 	map<string, int> map;
 	for(auto x: map)
 		x.second = 0;
 	int n, ans = 0;
 	cin >> n;

 	for(int i = 0; i < n; i++) {
 		string c, s;
 		cin >> c >> s;
 		c = c.substr(0,2);
 		if(c!=s)
 			ans += map[s+c];
 		map[c+s]++;
 	}
 	cout << ans;
 	return 0;
}