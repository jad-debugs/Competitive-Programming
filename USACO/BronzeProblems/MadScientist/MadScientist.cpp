/*ID: jadDebugs
TASK: Mad Scientist
LANG: C++
*/
#include <iostream> // bits/stdc++.h
#include <stdio.h>
#include <string>
using namespace std;
int main() {
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    bool lastCounted = false;
    long long ans = 0;
    long long cows;
    string cow_order;
    string order;

    cin >> cows;
    cin >> cow_order >> order;

    for(long long i=0; i<cows; i++) {
    	if(cow_order[i] != order[i]) {
      		if(!lastCounted) {
        		lastCounted = true;
        		ans++;
      		}
    	} 
    else {
     	lastCounted = false;
    }
  }
  cout << ans << endl;
    return 0;
}
