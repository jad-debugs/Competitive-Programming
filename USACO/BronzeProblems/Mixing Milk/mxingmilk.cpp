/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
	freopen("mixmilk.in","r",stdin);
 	freopen("mixmilk.out","w",stdout);
 	
 	long long a[2];
 	long long b[2];
 	long long c[2];
 	long change;

 	cin >> a[1] >> a[0];
 	cin >> b[1] >> b[0];
 	cin >> c[1] >> c[0];

 	for(int i = 1; i <= 33; i++){
		change = min(a[0],b[1]-b[0]);
	 	a[0] = a[0] - change;
	 	b[0] = b[0] + change;
	 	
	 	
 		change = min(b[0],c[1]-c[0]);
 		b[0] = b[0] - change;
 		c[0] = c[0] + change;

 		
 		change = min(c[0],a[1]-a[0]); // 0 0 12
 		c[0] = c[0] - change;
 		a[0] = a[0] + change;
 		
 	}
 		change = min(a[0],b[1]-b[0]);
	 	a[0] = a[0] - change;
	 	b[0] = b[0] + change;


 		cout << a[0] << endl << b[0] << endl << c[0];
 	return 0;
}