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
 
    ll mods[n] = {0};
 
    for(int i = 0; i < n; i++) {
        int a; cin >> a;

        pf += (a%n + n)%n;
        mods[pf%n]++;
    }
 
    ll ans = mods[0]; // is element == 0 (mod n), then that is a sub array
    for(ll x: mods)
        ans += x*(x-1)/2;
        // faster way for nC2;
    cout << ans;
 
    return 0;
}