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

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    stack<pii> s;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push({v[i], i});
            continue;
        }

        while (!s.empty() && s.top().f <= v[i]) {
            ans += i - s.top().s+1;
            s.pop();
        }

        s.push({v[i], i});
    }

    s = stack<pii>();

    for (int i = n-1; i >= 0; i--) {
        if (s.empty()) {
            s.push({v[i], i});
            continue;
        }

        while (!s.empty() && s.top().f <= v[i]) {
            ans += s.top().s - i + 1;
            s.pop();
        }

        s.push({v[i], i});
    }

    cout << ans;

    return 0;
}
