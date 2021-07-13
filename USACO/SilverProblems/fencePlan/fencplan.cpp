#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int hi = 2e5;

vector<int> graph[hi];
vector<pii> cows(hi);
vector<bool> visited(hi);

int mnx = 1e9, mxx = 0, mny = 1e9, mxy = 0;

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = 1;

    int r = cows[node].f;
    int c = cows[node].s;

    mnx = min(mnx, r);
    mxx = max(mxx, r);
    mny = min(mny, c);
    mxy = max(mxy, c);

    for (int u : graph[node]) {
        if (!visited[u])
            dfs(u);
    }
}

int main()
{
    int n, m; cin >> n >> m;


    for (int i = 1; i <= n; i++) {
        cin >> cows[i].f >> cows[i].s;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll ans = 2e9;

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        dfs(i);
        ll tmp = (mxx-mnx)*2LL + (mxy-mny)*2LL;
        ans = min(ans, tmp);
        mnx = 1e9, mxx = 0, mny = 1e9, mxy = 0;
    }

    cout << ans;

    return 0;
}
