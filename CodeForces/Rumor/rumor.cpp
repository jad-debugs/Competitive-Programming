#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6;

int n, m;
vector<int> graph[ma];
vector<int> CCnodes;

void dfs(int node, bool visited[]) {
    if(visited[node]) return;
    visited[node] = true;

    for(int u : graph[node])
        dfs(u, visited);
}


int dfsMIN(int node, bool visited[], int gold[], int mi) {
    mi = min(mi, gold[node-1]);
    if(visited[node]) return 0;
    visited[node] = true;

    for(int u : graph[node])
        dfs(u, visited);
    return mi;
}

void connected_components() {
    bool visited[ma] = {false};

    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            CCnodes.push_back(v);
            dfs(v, visited);
        }
    } 
}

int main()
{
    cin >> n >> m;
    int gold[n];

    for(int i = 0; i < n; i++) cin >> gold[i];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    connected_components();
    
    int ans = 0;
    for(int node : CCnodes) {
        bool visited[ma] = {false};
        ans += dfsMIN(node, visited, gold, 1000000000);    
    } 
    cout << ans;
    return 0;
}
