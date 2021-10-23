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

    int n; cin >> n;

    ll sum = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(x, mx);
        sum += x;
    }

    int ans1 = ceil(sum*1.0/(n-1));

    cout << max(ans1, mx);

    return 0;
}
