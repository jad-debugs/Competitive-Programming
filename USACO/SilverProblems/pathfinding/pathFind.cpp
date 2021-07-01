#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    bool adj[n+10][n+10];

    vector<int> sol(n+1, 2*n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    queue<int> q;
    sol[m] = 0;
    q.push(m);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (adj[cur][i] && sol[i] == 2*n) {
                sol[i] = sol[cur] + 1;
                q.push(i);
            }
        }
    }

    vector<pair<int, int>> ans;

    for (int i = 1; i <= n; i++) {
        ans.push_back({sol[i], i});
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < n-1; i++) {
        cout << ans[i].second;
        if (ans[i+1].first == ans[i].first)
            cout << ' ';
        else
            cout << endl;
    }

    if (ans[n-1].first != 2*n)
        cout << ans[n-1].second;

    return 0;
}
