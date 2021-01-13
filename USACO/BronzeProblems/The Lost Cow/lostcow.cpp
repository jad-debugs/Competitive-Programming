/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
  freopen("lostcow.in","r",stdin);
  freopen("lostcow.out","w",stdout);  
  int x, y;
  cin >> x >> y;

  int ans = 0;
  int by = 1;
  int dir = 1;
  while(true) {

    if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) {
      ans += abs(y-x);
      cout << ans << endl;
      break;
    } else {
      ans += by*2;
      by *= 2;
      dir *= -1;
    }
  }
}