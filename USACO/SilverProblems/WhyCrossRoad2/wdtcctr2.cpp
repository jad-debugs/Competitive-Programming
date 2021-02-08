// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}


int main()
{
    setIO("maxcross");

    int n, k, b; cin >> n >> k >> b;

    map<int, bool> m;

    for(int i = 0; i < b; i++) {
        int a; cin >> a;
        m[a] = 1;
    }

    int arr[n+1] = {0}; // remember to count from 1, not 0

    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] + m[i];
    }

    int ans = (int)1e5;

    for(int i = 1; i <= n-k+1; i++) {
        ans = min(ans, arr[i+k-1] - arr[i]);
    }

    cout << ans;
    return 0;
}
