#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        if (n == 1)
            cout << 20;
        else if (n == 2)
            cout << 36;
        else if (n == 3)
            cout << 51;
        else if (n == 4)
            cout << 60;
        else {
            long long mod = n%4;
            long long ans = ((n-mod)/4)*44;
            if (mod == 0)
                ans += 16;
            else if (mod == 1)
                ans += 32;
            else if (mod == 2)
                ans += 44;
            else if (mod == 3)
                ans += 55;
            cout << ans;
        }
        cout << '\n';
    }
}
