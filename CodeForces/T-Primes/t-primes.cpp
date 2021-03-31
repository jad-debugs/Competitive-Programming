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

const int MX = 2e6;

bool primes[MX+1];
set<ll> tPrime;

void sieve() {
    memset(primes, 1, MX+1);
    for (ll i = 2; i*i <= MX; i++) {
        if (primes[i]) {
            for (ll j = i*i; j <= MX; j += i)
                primes[j] = 0;
        }
    }
    for (ll i = 2; i <= MX; i++) {
        if (primes[i])
            tPrime.insert(i*i);
    }
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

    int n; cin >> n;

    sieve();

    for (int i = 0; i < n; i++) {
        ll a; cin >> a;        
        if (tPrime.count(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
