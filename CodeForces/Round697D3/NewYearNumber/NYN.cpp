#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        while(n >= 2020) {
            if(n%10 != 0) n -= 2021;
            else n -= 2020;
        }
        if(n == 0) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
