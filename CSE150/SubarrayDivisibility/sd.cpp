// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

    ll pf = 0;

    map<ll, int> m;

    m[0] = 1;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        pf = (pf + a)%n;

        m[pf]++;
    }

    int ans = 0;
    for(pair<ll, int> x : m)
        ans += x.second-1; 

    cout << ans;

    return 0;
}
