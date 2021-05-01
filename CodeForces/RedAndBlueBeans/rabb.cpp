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
}


int main()
{
    setIO("");

    int t; cin >> t;

    while (t--) {
        ll a, b, d; cin >> a >> b >> d;
        if (min(a, b)*(d+1) >= max(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
