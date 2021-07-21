#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int dim = 205;

struct cow {
    int x, y;
    ll p;
};

int n, ans = 0, tmp = 0;

vector<int> graph[dim];
vector<bool> visited(dim);

void dfs(int node)
{
    visited[node] = 1;
    tmp++;

    for (int u: graph[node]) {
        if (!visited[u])
            dfs(u);
    }
}

int main()
{
    cin >> n;

    vector<cow> cows(n);

    for (int i = 0; i < n; i++) {
        int x, y, p; cin >> x >> y >> p;
        cows[i] = {x, y, p*p};
    }

    // find all edges between cows
    for (int i = 0; i < n; i++) {
        cow cow1 = cows[i];
        for (int j = i+1; j < n; j++) {
            cow cow2 = cows[j];
            ll distX = abs(cow2.x - cow1.x);
            ll distY = abs(cow2.y - cow1.y);
            ll dist = distX*distX+distY*distY;
            if (cow1.p >= dist)
                graph[i].push_back(j);
            if (cow2.p >= dist)
                graph[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        tmp = 0;
        dfs(i);
        ans = max(tmp, ans);
        fill(visited.begin(), visited.end(), 0);
    }

    cout << ans;

    return 0;
}
