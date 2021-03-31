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

const int hi = 3e4;
int n, m;

map<pii, vector<pii>> graph;
bool visited[hi][hi];
bool matrix[hi][hi] = {0};

int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};

bool pastVisited(pii node)
{
    for (int i = 0; i < 4; i++) {
        if (node.f + dirx[i] < 0 || node.f + dirx[i] >= n ||
        node.s + diry[i] < 0 || node.s + diry[i] >= n)
            continue;
        if (matrix[node.f+dirx[i]][node.s+diry[i]])
            return true;
    }
    return false;
}

void dfs(pii node)
{
    if (visited[node.f][node.s] || node.f < 0 || node.f >= n || node.s < 0 || node.s >= n)
        return;

    visited[node.f][node.s] = 1;
    for (pii u: graph[node]) {
        matrix[u.f][u.s] = 1;
        if (pastVisited({u.f, u.s}))
            dfs({u.f, u.s});
    }
    // ff
    for (int i = 0; i < 4; i++) {
        if (matrix[node.f+dirx[i]][node.s+diry[i]])
            dfs({node.f+dirx[i], node.s+diry[i]});
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
    setIO("lightson");

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        x--;y--;a--;b--;
        graph[{x, y}].push_back({a, b});
    }

    matrix[0][0] = 1;

    dfs({0, 0});

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}
