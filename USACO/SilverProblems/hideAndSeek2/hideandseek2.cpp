#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

vector<int> graph[1005];
vector<bool> visited(1005);
vector<int> sol(1005);

int main()
{
    int n, m; cin >> n >> m;

    // 1 index for nodes !!!

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int u: graph[node]) {
            if (!visited[u]) {
                sol[u] = sol[node]+1;
                visited[u] = 1;
                q.push(u);
            }
        }
    }

    int ans = 0, dist = 0, rep = 0;
    for (int i = 1; i <= n; i++) {
        if (sol[i] > dist) {
            ans = i;
            rep = 1;
            dist = sol[i];
        }
        else if (sol[i] == dist) {
            rep++;
        }
    }

    cout << ans << ' ' << dist << ' ' << rep;

    return 0;
}
