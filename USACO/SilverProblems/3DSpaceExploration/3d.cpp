#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int dim = 130;

struct obj {
    int x, y, z;
};

// z, x, y
char graph[dim][dim][dim];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs(int a, int b, int c)
{
    queue<obj> q;
    graph[a][b][c] = 'X'; // mark as visited
    // put into form x, y, z, for given a, b, c in form z, x, y
    q.push({b, c, a});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;

        q.pop();

        for (int i = 0; i < 6; i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            int zz = z+dz[i];
            if (xx < 0 || yy < 0 || zz < 0)
                continue;
            if (graph[zz][xx][yy] == '*') {
                graph[zz][xx][yy] = 'X';
                q.push({xx, yy, zz});
            }
        }
    }
}

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = 0; a < n; a++) {
                cin >> graph[i][j][a];
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = 0; a < n; a++) {
                if (graph[i][j][a] == '*') {
                    ans++;
                    bfs(i, j, a);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
