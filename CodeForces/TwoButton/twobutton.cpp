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

    int a, b; cin >> a >> b;

    if (a >= b) {
        cout << a - b;
        return 0;
    }

    ll ans = 0;

    while (true) {
        if (b <= a) {
            cout << a-b + ans;
            break;
        }
        ans++;
        if (b % 2 == 0)
            b >>= 1;
        else
            b++;
    }

    return 0;
}
