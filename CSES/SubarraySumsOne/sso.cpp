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

    ll n, target;
    cin >> n >> target;

    ll pf[n];
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        cnt += a;
        pf[i] = cnt;
    }
    map<ll, ll> map;
    map[0] = 1;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += map[pf[i] - target];
        map[pf[i]]++;
    }
    cout << ans;
    return 0;
}
