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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m; cin >> n >> m;

    ll boys = 0, girls = 0;
    ll b1 = 0, b2 = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        boys += a;
        if (a > b1) {
            b2 = b1;
            b1 = a;
        }
        else if (a > b2)
            b2 = a;
    }
    ll g; cin >> g;
    girls += g;
    for (int i = 1; i < m; i++) {
        ll a; cin >> a;
        girls += a;
        g = min(g, a);
    }

    if (b1 > g) {
        cout << "-1\n";
        return 0;
    }

    if (b1 == g) {
        cout << boys*m + girls - b1*m << '\n';
    }
    else
        cout << boys*m + girls - b1*(m-1) - b2 << '\n';

    return 0;
}
