// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

const int hi = 2e5;

vector<int> graph[hi];
bool visited[hi];
bool ans[hi];

void dfs(int node, bool val)
{
    if(visited[node]) return;

    visited[node] = true;

    ans[node] = val;

    for(int u: graph[node]) {
        if(val == 0)
            dfs(u, 1);
        else
            dfs(u, 0);
    }
}

int main()
{
    setIO();

    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a, b});
    }

    for(int i = 1; i <= n; i++) {
        dfs(i, 0);
    }

    for(auto x: edges) {
        if(ans[x.first] == ans[x.second]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        (ans[i] == 0) ? cout << 1 : cout << 2;
        cout << " ";
    }

    return 0;
}
