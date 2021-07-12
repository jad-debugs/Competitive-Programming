// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t; cin >> t;

    for (ll z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        ll g00, g01, g02, g10, g12, g20, g21, g22;
        cin >> g00 >> g01 >> g02 >> g10 >> g12 >> g20 >> g21 >> g22;

        ll ans = 0;
        if (g02 - g01 == g01 - g00)
            ans++;
        if (g22 - g21 == g21 - g12)
            ans++;
        if (g00 - g10 == g10 - g20)
            ans++;
        if (g22 - g12 == g12 - g02)
            ans++;
        
        map<ll, ll> map;

        ll m1 = g01 + g21, m2 = g10 + g12, m3 = g00 + g22, m4 = g20 + g02, tmp = 0;

        if (m1 % 2 == 0) {
            map[m1/2]++;
            tmp = max(tmp, map[m1/2]);
        }
        if (m2 % 2 == 0) {
            map[m2/2]++;
            tmp = max(tmp, map[m2/2]);
        }
        if (m3 % 2 == 0) {
            map[m3/2]++;
            tmp = max(tmp, map[m3/2]);
        }
        if (m4 % 2 == 0) {
            map[m4/2]++;
            tmp = max(tmp, map[m4/2]);
        }
        cout << ans + tmp << "\n";
    }

    return 0;
}
