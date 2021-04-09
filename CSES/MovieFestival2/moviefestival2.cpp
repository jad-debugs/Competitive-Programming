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
    vector<pii> movies(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        movies[i] = {b, a};
    }

    sort(movies.begin(), movies.end());

    multiset<int> endTimes;

    for (int i = 0; i < k; i++)
        endTimes.insert(0);

    int ans = 0;
    for (pii x: movies) {
        auto ptr = endTimes.upper_bound(x.s);
        if (ptr == endTimes.begin()) continue;
        ptr--;
        endTimes.erase(ptr);
        endTimes.insert(x.f);
        ans++;
    }
    cout << ans;
    return 0;
}
