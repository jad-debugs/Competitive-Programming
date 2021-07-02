#include <iostream>
#include <queue>

using namespace std;

// submit with no functions or header files

void solve()
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n;
    cin >> n;
    
    char graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    queue<pair<int, int>> q;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == '*') {
                ans++;
                q.push({i, j});
                graph[i][j] = '.';

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int r2 = r+dx[k];
                        int c2 = c+dy[k];
                        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n) {
                            continue;
                        }
                        if (graph[r2][c2] == '*') {
                            graph[r2][c2] = '.';
                            q.push({r2, c2});
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}

int main()
{
    solve();
}