#include <iostream>
#include <vector>
using namespace std;

const int hi = 1e5+5;

vector<int> graph[hi];
vector<bool> visited(hi);

int ans = 0;

void dfs(int node)
{
    if (visited[node] == true)
        return;
    visited[node] = true;

    for (int u: graph[node]) {
        if (visited[u] == true)
            continue;
        ans++;
        dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    // double res = ans
    
    return 0;
}