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

const int hi = 2e5;
vector<bool> visited(hi);
vector<int> graph[hi];
vector<pii> components(hi);

int comp2 = 0;

void dfs(int node, int cc, int n)
{
    if (visited[node])
        return;

    if (node == n)
        comp2 = cc;

    components[cc].f = min(components[cc].f, node);
    components[cc].s = max(components[cc].s, node);

    visited[node] = 1;
    for (int u: graph[node]) {
        dfs(u, cc, n);
    }
}

int comp(int i1, int i2)
{
    int a = components[i1].f, b = components[i1].s;
    int c = components[i2].f, d = components[i2].s;

    int diff1 = min(abs(a - c), abs(a - d));
    int diff2 = min(abs(b - c), abs(b - d));

    return min(diff1, diff2);
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
    setIO("");

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        fill(visited.begin(), visited.end(), false);
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        components.clear();
        components.resize(hi);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cc = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                components[cc] = {i, i};
                dfs(i, cc, n);
                cc++;
            }
        }

        if (comp2 == 0) {
            cout << 0 << "\n";
        }
        else {
            ll ans = comp(0, comp2);
            ans *= ans;

            for (int i = 1; i < cc; i++) {
                ll d1 = comp(0, i);
                ll d2 = comp(i, comp2);
                ans = min(d1*d1 + d2*d2, ans);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
