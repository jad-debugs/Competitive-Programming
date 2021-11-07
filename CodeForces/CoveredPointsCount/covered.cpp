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

    int n; cin >> n;

    map<ll, ll> map;
    vector<pair<ll, ll>> p;

    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        map[a]++;
        map[b+1]--;
    }

    for (auto x: map) {
        p.push_back({x.f, x.s});
    }

    vector<ll> ans(n+1);

    const int sz = p.size();


    int cur = 0;
    for (int i = 0; i < sz-1; i++) {
        cur += p[i].s;
        ans[cur] += p[i+1].f - p[i].f;
        // cout << p[i].f << " " << p[i].s << "\n";
    }

    for (int i = 1; i < n; i++)
        cout << ans[i] << ' ';
    cout << ans[n];

    return 0;
}
