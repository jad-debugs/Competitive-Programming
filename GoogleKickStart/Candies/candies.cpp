// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((ll)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    ll t; cin >> t;
    for (ll z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        ll n, q, ans = 0; cin >> n >> q;
        vector<ll> org(n);

        for (ll i = 0; i < n; i++)
            cin >> org[i];
        vector<ll> d1(n+1); vector<ll> d2(n+1);

        ll sign = 1;
        for (ll i = 1; i <= n; i++) {
            d1[i] = sign*org[i-1] + d1[i-1];
            d2[i] = d2[i-1] + i*org[i-1]*sign;
            sign = -sign;
        }

        for (ll i = 0; i < q; i++) {
            char c; cin >> c;
            ll l, r; cin >> l >> r;
            if (c == 'U') {
                org[l-1] = r;
                sign = 1;
                for (ll j = 1; j <= n; j++) {
                    d1[j] = sign*org[j-1] + d1[j-1];
                    d2[j] = d2[j-1] + j*org[j-1]*sign;
                    sign = -sign;
                }
            }
            else {
                ans += (l&1 ? 1 : -1)*(d2[r] - d2[l-1] - (l-1)*(d1[r] - d1[l-1]));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
