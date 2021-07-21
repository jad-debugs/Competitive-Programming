#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int dim = 2e5;

vector<int> graphS[dim];
vector<int> graphD[dim];
int type[dim] = {0}, ans = 0;
bool works = 1;

void dfs(int node, int color)
{
    if (!works)
        return;
    type[node] = color;

    for (int u: graphS[node]) { 
        if (type[u] == 3 - color) {
            works = false;
            return;
        }
        if (type[u] == 0) {
            dfs(u, color);
        }
    }
    for (int u: graphD[node]) {
        if (type[u] == color) {
            works = false;
            return;
        }
        if (type[u] == 0) {
            dfs(u, 3-color);
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int a, b; cin >> a >> b;

        if (c == 'S') {
            graphS[a].push_back(b);
            graphS[b].push_back(a);
        }
        
        else {
            graphD[a].push_back(b);
            graphD[b].push_back(a);
        }        
    }

    for (int i = 1; i <= n; i++) {
        if (type[i] == 0) {
            dfs(i, 1);
            ans++;
        }
    }

    if (!works) {
        cout << "0\n";
    }
    else {
        cout << 1;
        for (int i = 0; i < ans; i++)
            cout << 0;
    }

    return 0;
}
