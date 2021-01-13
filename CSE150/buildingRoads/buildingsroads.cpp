#include <iostream>
#include <vector>
using namespace std;

const int ma = 1e5+10;
int n; int m;

vector<int> graph[ma];
bool visited[ma] = {false};
int ans[ma];

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(int u : graph[node]) {
        dfs(u);
    }
}

int connected_components() {
    int count = 0;
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            ans[count++] = v;
            dfs(v);
        }
    }
    return count;
}

int main()
{
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cc = connected_components() - 1;
    cout << cc << "\n";
    for(int i = 1; i <= cc; i++) {
        cout << ans[i-1] << " " << ans[i] << "\n";
    }
    return 0;    
}
