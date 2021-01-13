#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[3001];
bool visited[3001] = {false};

void dfs(int node, bool visited[]) {
    if(visited[node]) return;
    visited[node] = true;
    for(int u : graph[node]) {
        dfs(u, visited);
    }
}

string isConnectedComponents(bool visited[]) {
    int count = 0;
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            count++;
            dfs(v, visited);
        }
    }
    if(count == 1) return "YES";
    return "NO";
}

int main()
{
    cin >> n >> m;

    bool visited[n+1] = {false};
    
    for(int e = 0; e < m; e++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << isConnectedComponents(visited) << "\n";
    for(int i = 0; i < n-1; i++) {
        int node; cin >> node;
        for(int j = 0; j <= n; j++) {
            for(int i = 0; i <= n; i++) visited[i] = false;
            graph[j].erase(remove(graph[j].begin(), graph[j].end(), node), graph[j].end());
        }
        cout << isConnectedComponents(visited) << "\n";
    }

    return 0;    
}
