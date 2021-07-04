#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n, m;

vector<vector<int>> graph(35, vector<int> (35));
vector<vector<ll>> sol(35, vector<ll> (35));
vector<vector<bool>> visited(35, vector<bool> (35));

int main() 
{
    cin >> n >> m;
    int d1, d2; cin >> d1 >> d2;

    int dx[4] = {d1, d1, -d1, -d1};
    int dy[4] = {d2, -d2, d2, -d2};


    pii start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 3)
                start = {i, j};
            if (graph[i][j] == 4)
                end = {i, j};
        }
    }

    // sol[start.f][start.s] = 0; -> implied
    queue<pii> q;
    q.push({start.f, start.s});

    while (!q.empty()) {
        int r = q.front().f;
        int c = q.front().s;
        visited[r][c] = 1;
        q.pop();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                int r2 = 0, c2 = 0;
                if (i == 0) {
                    r2 = r + dx[j];
                    c2 = c + dy[j];
                }
                else {
                    r2 = r + dy[j];
                    c2 = c + dx[j];
                }
                if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && (graph[r2][c2] == 1 || graph[r2][c2] == 4) && !visited[r2][c2]) {
                    visited[r2][c2] = 1;
                    sol[r2][c2] = sol[r][c] + 1;
                    if (graph[r2][c2] == 4) {
                        cout << sol[r2][c2];
                        return 0;
                    }
                    q.push({r2, c2});
                }
            }
        }
    }

    return 0;
}
