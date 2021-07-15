#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int dim = 2e5;
int cc = 1;

vector<int> graph[dim];
bool visited[dim];
int component[dim];

string milkType;

void dfs(int node, char type)
{
    visited[node] = 1;
    component[node] = cc;

    for (int u: graph[node]) {
        if (!visited[u] && milkType[u-1] == type) {
            component[u] = cc;
            dfs(u, type);
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;

    cin >> milkType;

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, milkType[i-1]);
            cc++;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        char c; cin >> c;

        if (component[a] != component[b]) {
            cout << 1;
            continue;
        }
        if (milkType[a-1] == c) {
            cout << 1;
            continue;
        }
        cout << 0;
    }

    return 0;
}
