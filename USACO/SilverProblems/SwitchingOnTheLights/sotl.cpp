// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cstdio>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int hi = 101;
int n, m;

map<pii, vector<pii> > graph;
bool visited[hi][hi] = {0};
bool matrix[hi][hi] = {0};

int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};

bool pastVisited(pii node)
{
    for (int i = 0; i < 4; i++) {
        int x = node.f+dirx[i], y = node.s+diry[i];
        if (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] && visited[x][y])
            return true;
    }
    return false;
}

void dfs(pii node)
{
    if (node.f < 0 || node.f >= n || node.s < 0 || node.s >= n || visited[node.f][node.s])
        return;

    visited[node.f][node.s] = 1;
    for (pii u: graph[node]) {
        if (!(matrix[u.f][u.s])) {
            matrix[u.f][u.s] = 1;
            if (pastVisited(u))
                dfs(u);
        }
    }
    // ff
    for (int i = 0; i < 4; i++) {
        if (matrix[node.f+dirx[i]][node.s+diry[i]])
            dfs({node.f+dirx[i], node.s+diry[i]});
    }
}

int main()
{
    freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

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

    cout << ans << '\n';
    return 0;
}

