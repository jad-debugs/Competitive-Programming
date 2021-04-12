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

ll const MOD = 1e9+7;

ll POW(ll a, ll b)
{
    return (b == 0 ? 1 : (!b & 1 ? POW(a, b/2) * POW(a, b/2) % MOD : POW(a, b-1) * (a%MOD) % MOD));
}

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

    ll primes[10] = {-1, 2, 11, 101, 1007, 10007, 100003, 1000003, 10000019, 100000007};

    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << (ll)pow(10, a-c)*primes[c] << ' ' << (ll)pow(10, b-c)*primes[c]+primes[c] << '\n';
    }

    return 0;
}
