/* 
ID: jadDebugs
TASK: milk2
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main()
{
    setIO("milk2");
    
    int n; cin >> n;
    vector<pair<int, int>> times(n);

    for (int i = 0; i < n; i++)
        cin >> times[i].f >> times[i].s;
    sort(times.begin(), times.end());

    int cur = times[0].s;
    int mx = 0;
    int l = 0, r = 0;

    while (l < n && r < n) {
        cur = times[l].s;
        while (r < n && times[r].f <= cur) {
            cur = max(times[r].s, cur);
            r++;
        }
        mx = max(mx, cur - times[l].f);
        l = r;
    }

    cout << mx << ' ';
    
    int mn = 0;
    int end = times[0].s;
    for (int i = 1; i < n; i++) {
        if (times[i].f > end) {
            mn = max(mn, times[i].f - end);
            end = times[i].s;
        }
        else if (times[i].s > end)
            end = times[i].s;
    }
    
    cout << mn << '\n';
    return 0;
}
