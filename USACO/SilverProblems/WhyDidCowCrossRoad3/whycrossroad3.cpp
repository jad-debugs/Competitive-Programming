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

int n, k, z, color = 0, ans;
// 1 -> k is color to check visited
int visited[101][101];
bool graph[101][101];
set<pair<pii, pii>> distant, road;

pii coor;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void ff(int r, int c)
{
    // not needed, but jic
    if (r < 0 || r > n || c < 0 || c > n || visited[r][c] == color)
        return;
    visited[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];

        if (r2 < 0 || r2 > n || c2 < 0 || c2 > n || visited[r2][c2] == color)
            continue;
        if (road.find({{r2, c2}, {r, c}}) != road.end())
            continue;

        if (graph[r2][c2]) {
            distant.insert({coor, {r2, c2}});
            if (distant.find({{r2, c2}, coor}) != distant.end())
                ans--;
        }

        ff(r2, c2);
    }
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
    // setIO("countcross");

    cin >> n >> k >> z;

    ans = (n*(n-1))/2;

    vector<pii> cows;

    for (int i = 0; i < z; i++) {
        int r, c, r2, c2; cin >> r >> c >> r2 >> c2;
        road.insert({{r, c}, {r2, c2}});
    }

    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        graph[r][c] = 1;
        cows.push_back({r, c});
    }

    for (pii p: cows) {
        color++;
        coor = p;
        ff(p.f, p.s);
    }

    // for (auto x: distant)
    //     cout << x.f.f << ' ' << x.f.s << " can reach " << x.s.f << ' ' << x.s.s << endl;

    cout << ans;

    return 0;
}
