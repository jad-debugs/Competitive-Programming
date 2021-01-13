/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("pails.in","r",stdin);
 	freopen("pails.out","w",stdout);

 	long long x, y, z, high=0, cur;
 	cin >> x >> y >> z;

 	for(int i = 0; i <= (z/x)*x; i+=x) {
 		for(int j = 0; j <= (z/y)*y; j+=y) {
 			cur = i+j;
 			if(cur <= z)
 				high = max(high, cur);
 		}
 	}
 	cout << high;
 	return 0;
}