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

string cows;

const int hi = 1e5+5;

vector<int> graph[hi];
pair<int, char> component[hi];

int cc = 0;

void dfs(int node, int parent)
{
    for (int u: graph[node]) {
        if (u == parent) {
            continue;
        }
        if (cows[u] == cows[node]) {
            component[u] = component[node];
        }
        else {
            char c = component[node].s == 'G' ? 'H' : 'G';
            component[u] = {++cc, c};
        }
        dfs(u, node);
    }
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
    setIO("milkvisits");

    int n, m; cin >> n >> m;

    cin >> cows;

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }

    component[0] = {0, cows[0]};
    dfs(0, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        char c; cin >> c;
        if (component[a].f != component[b].f)
            cout << 1;
        else {
            if (component[a].s == c)
                cout << 1;
            else
                cout << 0;
        }
    }

    return 0;
}
