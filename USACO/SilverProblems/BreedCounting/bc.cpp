// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}


int main()
{
    setIO("bcount");

    int n, q; cin >> n >> q;

    int h[n+1] = {0}, g[n+1] = {0}, j[n+1] = {0};

    for(int i = 1; i < n+1; i++) {
        int t; cin >> t;
        if(t == 1) {
            h[i] += h[i-1] + 1;
            g[i] += g[i-1];
            j[i] += j[i-1];
        }
        else if(t == 2) {
            h[i] += h[i-1];
            g[i] += g[i-1] + 1;
            j[i] += j[i-1];
        }
        else {
            h[i] += h[i-1];
            g[i] += g[i-1];
            j[i] += j[i-1] + 1;
        }
    }

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << h[b] - h[a-1] << " "
            << g[b] - g[a-1] << " "
            << j[b] - j[a-1] << "\n";
    }

    return 0;
}