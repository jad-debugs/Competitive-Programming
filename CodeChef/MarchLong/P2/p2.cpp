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

    int n, h, x; cin >> n >> h >> x;
    int hi = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > hi)
            hi = a;
    }

    h - x <= hi ? cout << "YES" : cout << "NO";

    return 0;
}
