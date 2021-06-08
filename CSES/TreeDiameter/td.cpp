// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5+5;
bool visited[mx] = {0};

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

vector<int> graph[mx];

int ans = 0, nNode = 0;

void dfs(int node, int dist)
{
    if (visited[node])
        return;
    visited[node] = 1;

    if (dist > ans) {
        ans = dist;
        nNode = node;
    }

    for (int u: graph[node]) {
        dfs(u, dist+1);
    }
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main()
{
    setIO("");

    int n; cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    for (int i = 0; i <= n+3; i++)
        visited[i] = 0;
    ans = 0;
    dfs(nNode, 0);
    cout << ans;

    return 0;
}
