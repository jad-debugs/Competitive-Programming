#include <iostream>
using namespace std;

int main()
{
    int n, a, b, c = 0, denied = 0; cin >> n >> a >> b;
    
    while(n--) {
        int p; cin >> p;
        
        if(p == 1) {
            if(a > 0) {
                a--;
            }
            else if (b > 0) {
                b--;
                c++;
            }
            else if (c > 0) {
                c--;
            }
            else {
                denied++;
            }
        }
        else if (p == 2) {
            if (b > 0) {
                b--;
            }
            else
                denied+=2;
        }
    }
    cout << denied;
    return 0;
}
