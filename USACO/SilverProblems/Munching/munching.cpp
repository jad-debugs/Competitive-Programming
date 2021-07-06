#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char graph[100][100] = {0};
int sol[100][100] = {0};

int main()
{
    int n, m; cin >> n >> m;    

    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'B')
                q.push({i, j});
        }
    }

    while (!q.empty()) {
        int r = q.front().f;
        int c = q.front().s;
        graph[r][c] = '-';
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r2 = r + dx[i];
            int c2 = c + dy[i];

            if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && (graph[r2][c2] == '.' || graph[r2][c2] == 'C')) {
                sol[r2][c2] = sol[r][c] + 1;
                if (graph[r2][c2] == 'C') {
                    cout << sol[r2][c2] << '\n';
                    return 0;
                }
                graph[r2][c2] = '-';
                q.push({r2, c2});
            }
        }
    }

    cout << "we didnt reach ??? debug time !\n";

    return 0;
}
