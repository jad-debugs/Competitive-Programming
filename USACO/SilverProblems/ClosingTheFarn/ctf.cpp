#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}

int cnt;

bool closed[3001] = {false}, visited[3001] = {false};

int n, m;
vector<int> graph[3001];

void dfs(int node) {
    if(visited[node] || closed[node]) return;
        cnt++;
    visited[node] = true;
    for(int u : graph[node]) {
        dfs(u);
    }
}

int main()
{
    setIO("closing");
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int remove[n];

    for(int i = 0; i < n; i++) cin >> remove[i];

    dfs(1);
    cout << (cnt == n ? "YES\n" : "NO\n");

    for(int i = 0; i < n-1; i++) {
        int node = remove[i];
        for(int j = 0; j <= n; j++)
            visited[j] = false;
        closed[node] = true;
        cnt = 0;
        dfs(remove[n-1]);
        cout << (cnt == n-i-1 ? "YES\n" : "NO\n");
    }
    return 0;
}
