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

int n;
const int makePos = 10000;
const int MX = 20005;
const int MOD = 1e9+7;

vector<pii> x[MX];
vector<pii> y[MX];

bool cmp(pii a, pii b)
{
    if (a.f == b.f)
        return a.s < b.s;
    return a.f < b.f; 
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
    setIO("triangles");

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a += makePos;
        b += makePos;
        x[a].push_back({b, i});
        y[b].push_back({a, i});
    }

    ll sumX[n] = {0};
    ll sumY[n] = {0};

    // summing y
    for (int i = 0; i < MX; i++) {
        int cntX = x[i].size(); // # of x coor that r same as r.a.
        if (cntX > 1) { // if <= 1, there wont be a triangle
            sort(begin(x[i]), end(x[i]), cmp);
            ll bS = 0;
            for (int j = 0; j < cntX; j++)
                bS += (x[i][j].f - x[i][0].f);
            bS %= MOD;
            sumY[x[i][0].s] = bS;

            for (int j = 1; j < cntX; j++) {
                bS += (2*j-cntX)*(x[i][j].f-x[i][j-1].f);
                bS %= MOD;
                sumY[x[i][j].s] = bS;
            }
        }
    }
    // summing x
    for (int i = 0; i < MX; i++) {
        int cntY = y[i].size(); // # of x coor that r same as r.a.
        if (cntY > 1) { // if <= 1, there wont be a triangle
            sort(begin(y[i]), end(y[i]), cmp);
            ll bS = 0;
            for (int j = 0; j < cntY; j++) {
                bS += (y[i][j].f - y[i][0].f);
            }
            bS %= MOD;
            sumX[y[i][0].s] = bS;

            for (int j = 1; j < cntY; j++) {
                bS += (2*j-cntY)*(y[i][j].f-y[i][j-1].f);
                bS %= MOD;
                sumX[y[i][j].s] = bS;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += (sumX[i]*sumY[i])%MOD;

    cout << ans%MOD;

    return 0;
}
