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

const int hi = 2e6;

vector<int> g1[hi];
vector<int> g2[hi];
vector<bool> visited(hi);

void dfs(int node, int &cnt, vector<int> graph[])
{
    if (visited[node])
        return;
    cnt++;
    visited[node] = 1;
    for (int u: graph[node])
        dfs(u, cnt, graph);
}

void setIO(string name = "") {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int n, e; cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    int cnt = 0;
    
    dfs(1, cnt, g1);

    if (cnt != n) {
        cout << "NO\n1 ";
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << i;
                break;
            }
        }
        return 0;
    }

    cnt = 0;
    fill(visited.begin(), visited.end(), 0);
    dfs(1, cnt, g2);

    if (cnt == n) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << i << " 1";
            break;
        }
    }

    return 0;
}
