#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    
    if(a != 1 && b != 1 && c != 1) {
        cout << a*b*c;
        return 0;
    }

    else {
       bool a1 = false, b1 = false, c1 = false;
       if(a == 1)
           a1=true;
       if(b==1)
           b1=true;
       if(c==1)
           c1=true;
       if(a1 && !b1 && !c1) {
           cout << (a+b)*c;
           return 0;
       }
       if(!a1 && b1 && !c1) {
           int mi = min(a,c); int ma = max(a,c);
           cout << (b+mi)*ma;
           return 0;
       }
       if(!a1 && !b1 && c1) {
           cout << (b+c)*a;
           return 0; 
       }
       if(a1 && b1 && !c1) {
           cout << (a+b)*c;
           return 0;
       }
       if(!a1 && b1 && c1) {
           cout << a*(b+c);
           return 0;
       }
       else {
           cout << a+b+c;
           return 0;
       }
    }
    return 0;
}
