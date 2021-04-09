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

const int MX = 3e3;
int n;
int grid[MX][MX];

bool y(pii p1, pii p2)
{
    return p1.s < p2.s;
}

ll pfSum(int x1, int y1, int x2, int y2)
{
    return (ll)(grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1]);
}

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

    cin >> n;

    pii points[n];

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        points[i] = {a, b};
    }

    // point compression
    sort(points, points+n);
    for (int i = 1; i <= n; i++) {
        points[i-1].f = i;
    }

    sort(points, points+n, y);
    for (int i = 1; i <= n; i++) {
        points[i-1].s = i;
    }

    for (int i = 0; i < n; i++) {
        grid[points[i].f][points[i].s] = 1;
    }
    
    // changing to pf
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    ll ans = n+1; // count empty subset and single subsets (saves some time)
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pii p1 = {points[i].f, points[i].s};
            pii p2 = {points[j].f, points[j].s};

            ans += pfSum(min(p1.f, p2.f), 1, max(p1.f, p2.f), min(p1.s, p2.s))*
                pfSum(min(p1.f, p2.f), max(p1.s, p2.s), max(p1.f, p2.f), n);
        }
    }
    cout << ans;
    return 0;
}
