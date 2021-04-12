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
        if (!(matrix[u.f][u.s])) {
            matrix[u.f][u.s] = 1;
            if (pastVisited(make_pair(u.f, u.s)))
                dfs(make_pair(u.f, u.s));
        }
    }
    // ff
    for (int i = 0; i < 4; i++) {
        if (matrix[node.f+dirx[i]][node.s+diry[i]])
            dfs(make_pair(node.f+dirx[i], node.s+diry[i]));
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
        graph[make_pair(x, y)].push_back(make_pair(a, b));
    }

    matrix[0][0] = 1;

    dfs(make_pair(0, 0));

    int ans = 0;

    for (int i = 0; i < hi; i++) {
        for (int j = 0; j < hi; j++) {
            if (matrix[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
