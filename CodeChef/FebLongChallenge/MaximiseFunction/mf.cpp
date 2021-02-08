#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        ll lo = 2e9L, hi = -2e9L;
        for(int i = 0; i < n; i++) {
            ll a; cin >> a;
            if(a < lo)
                lo = a;
            if(a > hi)
                hi = a;
        }
        cout << 2*(hi-lo) << "\n";
    }
    return 0;
}