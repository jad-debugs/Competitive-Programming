// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int hi = 5005;
int ans = 0;

vector<bool> visited(hi);
int edges[hi][hi] = {0};
vector<int> graph[hi];

void dfs(int node, int k)
{
    visited[node] = 1;

    for (int u: graph[node]) {
        if (!visited[u] && edges[u][node] >= k) {
            ans++;
            dfs(u, k);
        }
    }
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("mootube");

    int n, q; cin >> n >> q;

    for (int i = 0; i < n-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges[a][b] = w;
        edges[b][a] = w;
    }

    for (int i = 0; i < q; i++) {
        int k, a; cin >> k >> a;

        dfs(a, k);
        cout << ans << '\n';

        ans = 0;
        fill(visited.begin(), visited.end(), 0);
    }

    return 0;
}
