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
int p, c;
bool graph[110][110];
bool visited[110];

void dfs(int node)
{
    if(visited[node]) return;

    visited[node] = true;

    for(int u = 0; u < p; u++) {
        if(graph[node][u])
            dfs(u);
    }
}


int main()
{
    setIO();

    while(cin >> p && cin >> c && (p || c)) {
        memset(graph, false, 110*110);
        vector<pair<int, int>> edges;
        for(int i = 0; i < c; i++) {
            int a, b; cin >> a >> b;
            graph[a][b] = true;
            graph[b][a] = true;
            edges.push_back({a, b});
        }
        string ans = "No\n";
        for(pair<int, int> x: edges) {
            int a = x.first;
            int b = x.second;
            graph[a][b] = false;
            graph[b][a] = false;

            memset(visited, false, 110);

            dfs(0);

            for(int a = 0; a < p; a++) {
                if(!visited[a]) 
                   ans = "Yes\n";
            }
            graph[a][b] = true;
            graph[b][a] = true;
        }
        cout << ans;
    }

    return 0;
}
