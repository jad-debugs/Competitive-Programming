#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool fence[4005][4005] = {0}; // acts as visited array, where fences are already visited

int main()
{

    int n; cin >> n;

    int x = 2002, y = 2002, minx = 1e8, maxx = 0, miny = 1e8, maxy = 0;

    fence[x][y] = 1;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        switch (c) {
            case 'S':
                fence[++x][y] = 1;
                fence[++x][y] = 1;
                break;
            case 'N':
                fence[--x][y] = 1;
                fence[--x][y] = 1;
                break;
            case 'E':
                fence[x][++y] = 1;
                fence[x][++y] = 1;
                break;
            case 'W':
                fence[x][--y] = 1;
                fence[x][--y] = 1;
                break;
            default:
                break;
        }
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxx, y);
    }

    queue<pii> q;

    int ans = 0;

    for (int i = minx-1; i <= maxx+1; i++) {
        for (int j = miny-1; j <= maxy+1; j++) {
            if (fence[i][j])
                continue;
            fence[i][j] = 1;
            ans++;

            q.push({i, j});

            while (!q.empty()) {
                int r = q.front().f;
                int c = q.front().s;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int r2 = r + dx[k];
                    int c2 = c + dy[k];
                    if (r2 >= 0 && r2 < 4005 && c2 >= 0 && c2 < 4005 && !fence[r2][c2]) {
                        fence[r2][c2] = 1;
                        q.push({r2, c2});
                    }
                }
            }
        }
    }

    cout << ans - 1;

    return 0;
}
