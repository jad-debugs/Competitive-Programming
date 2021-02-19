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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}

const int hi = 2e5;

vector<int> graph[hi];
bool visited[hi];
bool colorNode[hi];

ll cc = 0;

void dfs(int node)
{
    if(visited[node]) return;
    visited[node] = true;

    for(int u: graph[node]) {
        dfs(u);
    }
}

int main()
{
    setIO("revegetate");

    int n, m; cin >> n >> m;

    set<int> diff;

    for(int i = 0; i < m; i++) {
        char ig; cin >> ig;
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        if(ig == 'D') {
            if(diff.count(a) || diff.count(b)) {
                cout << 0;
                return 0;
            }
            diff.insert(a);
            diff.insert(b);
        }
    }

    for(int i = 0; i < n; i++) {
        bool x;
        if(!visited[i]) {
            dfs(i);
            cc++;
        }
    }

    cout << 1;
    for(int i = 0; i < cc; i++)
        cout << 0;

    return 0;
}
