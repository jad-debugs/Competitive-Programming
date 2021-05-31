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

const int hi = 1e4+5;

vector<int> graph[hi];

int ans = 0;
int visited[hi] = {0};

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = 1;
    for (int u: graph[node]) {
            dfs(u);
    }
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO();
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans;

    return 0;
}
