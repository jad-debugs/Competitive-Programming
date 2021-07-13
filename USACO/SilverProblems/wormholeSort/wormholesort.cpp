#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

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

    int n, m; cin >> n >> m;

    vector<int> cows(n+10);

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        cows[i] = a;
    }

    vector<pii> graph[n+10];

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> sol(n+10);
    sol[1] = 2e9;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (pii x: graph[node]) {
            int u = x.f;
            int w = x.s;
            int mn = min(sol[node], w);
            if (mn > sol[u]) {
                sol[u] = mn;
                q.push(u);
            }
        }
    }

    int ans = 2e9;
    for (int i = 1; i <= n; i++) {
        if (cows[i] == i)
            continue;
        ans = min(ans, sol[i]);
    }

    cout << (ans == (int)2e9 ? -1: ans) << "\n";

    return 0;
}