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

int n, k, z;
bool visited[105][105];
int graph[105][105];

set<pair<pii, pii>> road;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int r, int c, int color)
{
    // not needed, but jic
    if (r <= 0 || r > n || c <= 0 || c > n || visited[r][c])
        return;
    
    visited[r][c] = 1;
    graph[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];

        if (road.find({{r, c}, {r2, c2}}) == road.end())
            dfs(r2, c2, color);
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
    setIO("countcross");

    cin >> n >> k >> z;

    int ans = 0;

    vector<pii> cows(k);

    for (int i = 0; i < z; i++) {
        int r, c, r2, c2; cin >> r >> c >> r2 >> c2;
        road.insert({{r, c}, {r2, c2}});
        road.insert({{r2, c2}, {r, c}});
    }

    for (int i = 0; i < k; i++) {
        cin >> cows[i].f >> cows[i].s;
    }

    int color = 0;
    for (int i = 0; i < k; i++) {
        if (!visited[cows[i].f][cows[i].s]) {
            color++;
            dfs(cows[i].f, cows[i].s, color);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (graph[cows[i].f][cows[i].s] != graph[cows[j].f][cows[j].s])
                ans++;
        }
    }

    cout << ans;

    return 0;
}

