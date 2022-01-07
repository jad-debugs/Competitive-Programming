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

    int n, k; cin >> n >> k;

    vector<int> factor;
    factor.push_back(0);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a = ceil(a/12.0)*12;
        if (find(factor.begin(), factor.end(), a) == factor.end())
            factor.push_back(a);
    }

    sort(factor.begin(), factor.end());

    vector<int> diff;

    for (int i = 1; i < (int)factor.size(); i++) {
        int d = factor[i] - factor[i-1] - 12;
        if (d == 0)
            continue;
        diff.push_back(d);
    }

    sort(diff.begin(), diff.end(), greater<int>());

    ll ans = 12*((int)factor.size()-1);

    for (int i = k-1; i < (int)diff.size(); i++) {
        ans += diff[i];
    }

    cout << ans;

    return 0;
}
