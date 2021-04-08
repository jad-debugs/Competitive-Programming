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

    vector<ll> diff;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        diff.push_back(a[i] - b[i]);
    sort(begin(diff), end(diff));
    ll ans = 0;
    int index = 0;
    for (ll x: diff) {
        if (x >= 1) {
            ans += n - index - 1;
            index++;
            continue;
        }
        index++;
        auto it = upper_bound(diff.begin(), diff.end(), -x);
        ans += (diff.end() - it);
    }
    cout << ans;
    return 0;
}
