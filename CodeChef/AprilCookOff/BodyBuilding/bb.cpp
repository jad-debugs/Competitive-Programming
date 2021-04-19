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
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");
    int t; cin >> t;
    while (t--) {
        int n, r; cin >> n >> r;

        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> diff(n);
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        ll ans = 0;
        ll cur = 0;

        diff[0] = 0;

        for (int i = 1; i < n; i++) {
            diff[i] = (a[i] - a[i-1])*r;
        }
        for (int i = 0; i < n; i++) {
            cur += b[i] - min(cur, diff[i]);
            if (cur > ans)
                ans = cur;
        }
        cout << ans << '\n';
    }
}
