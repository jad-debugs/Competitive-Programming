// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

typedef ll long long
typedef f first
typedef s second
typedef pii pair<int, int>

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

const int hi = 2e5;
vector<int> graph[hi];
bool visited[hi];
ll g1 = 0, g2 = 0;

void dfs(int node, bool cur)
{
    if(visited[node]) return;

    visited[node] = true;

    if(!cur)
        g1++;
    else
        g2++;

    for(int u: graph[node]) {
        if(cur)
            dfs(u, 0);
        else
            dfs(u, 1);
    }
}

int main()
{
    setIO();

    int n; cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    cout << g1 * g2 - (n-1);

    return 0;
}
