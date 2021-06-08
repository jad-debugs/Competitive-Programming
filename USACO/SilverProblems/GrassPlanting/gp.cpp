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
    setIO("planting");

    int n; cin >> n;
    
    vector<int> g(n);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;

        g[a-1]++;
        g[b-1]++;
    }

    int ans = 0;

    for (int x: g)
        ans = max(ans, x);

    cout << ans+1 << '\n';

    return 0;
}
