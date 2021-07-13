#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

vector<pii> graph[105][105];
bool visited[105][105];
bool lights[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

bool redo(int r, int c)
{
    for (int i = 0; i < 4; i++) {
        int r2 = r+dx[i];
        int c2 = c+dy[i];
        if (r2 >= 1 && r2 <= n && c2 >= 1 && c2 <= n && lights[r2][c2] && visited[r2][c2]) {
            return true;
        }
    }
    return false;
}

void dfs(int r, int c)
{
    if (r < 1 || r > n || c < 1 || c > n || visited[r][c]) {
        return;
    }
    visited[r][c] = 1;

    for (pii u: graph[r][c]) {
        if (!lights[u.f][u.s]) {
            lights[u.f][u.s] = 1;
            if (redo(u.f, u.s))
                dfs(u.f, u.s);
        }
    }

    for (int i = 0; i < 4; i++) {
        int r2 = r+dx[i];
        int c2 = c+dy[i];
        if (r2 >= 1 && r2 <= n && c2 >= 1 && c2 <= n && lights[r2][c2]) {
            dfs(r2, c2);
        }
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
    setIO("");

    int m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        graph[x1][y1].push_back({x2, y2});
    }

    lights[1][1] = 1;
    dfs(1, 1);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (lights[i][j])
                ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
