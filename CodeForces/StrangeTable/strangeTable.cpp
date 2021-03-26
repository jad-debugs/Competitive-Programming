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
        ll n, m, num; cin >> n >> m >> num;
        pair<ll, ll> col;
        ll col1 = num%n;
        if (col1 == 0)
            col1 = n;
        col.f = col1;
        col.s = (num-col.f)/n;

        cout << (col.f-1)*m+1 + col.s << "\n";
    }

    return 0;
}
