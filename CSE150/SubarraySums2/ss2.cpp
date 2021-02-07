// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int hi = (int)3e9;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}


int main()
{
    setIO();

    int n; cin >> n;
    int x; cin >> x;

    map<ll, int> m;

    m[0] = 1;

    ll pf = 0;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        pf += a;
        
        ans += m[pf-x];

        m[pf]++;
    }

    cout << ans;

    return 0;
}
