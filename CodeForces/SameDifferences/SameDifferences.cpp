#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // a_j - j = a_i - i
    // 2 3 -2 0 1 0
    
    // 1 5 1 1 1 1

    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        map<ll, ll> map;

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            ans += map[a-i];
            map[a - i]++;
        }

        cout << ans << '\n';
    }
    return 0;
}