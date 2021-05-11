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

    ll n; cin >> n;
    ll l = 0, r = 1e12;

    while (l < r) {
        ll mid = l + (r - l)/2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += min((ll)n, mid/i);
        if (cnt > n*n/2LL)
            r = mid;
        else
            l = mid+1;
    }
    cout << r << '\n';
    return 0;
}
