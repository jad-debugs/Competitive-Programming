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

const int mx = 2007;

int cows[mx][mx];
int pf[mx][mx];

bool cmp(pii a, pii b)
{
    return a.s < b.s;
}

int getCows(int x1, int y1, int x2, int y2)
{
    return (pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1]);
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
    setIO("balancing");

    int n; cin >> n;

    vector<pii> coor(n);

    for (int i = 0; i < n; i++)
        cin >> coor[i].f >> coor[i].s;

    // coordinate compression with common points as odds

    sort(coor.begin(), coor.end());

    int prev = 0;
    for (int i = 0, j = 1; i < n; i++, j+=2) {
        if (coor[i].f == prev)
            j -= 2;
        prev = coor[i].f;
        coor[i].f = j;
    }

    sort(coor.begin(), coor.end(), cmp);

    prev = 0;
    for (int i = 0, j = 1; i < n; i++, j+=2) {
        if (coor[i].s == prev)
            j -= 2;
        prev = coor[i].s;
        coor[i].s = j;
    }


    // cows on graph
    for (int i = 0; i < n; i++) {
        cows[coor[i].f][coor[i].s]++;
    }

    // creating 2d pf sum arrray
    for (int i = 1; i <= n*2; i++) {
        for (int j = 1; j <= n*2; j++) {
            pf[i][j] = cows[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int ans = 2e9;

    for (int i = 2; i <= 2*n; i+=2) {
        for (int j = 2; j <= 2*n; j+=2) {
            int area1 = getCows(1, 1, i, j);
            int area2 = getCows(1, j, i, 2*n);
            int area3 = getCows(i, 1, 2*n, j);
            int area4 = getCows(i, j, 2*n, 2*n);

            int curMax = max(area1, max(area2, max(area3, area4)));
            ans = min(ans, curMax);
        }
    }

    cout << ans;

    return 0;
}
