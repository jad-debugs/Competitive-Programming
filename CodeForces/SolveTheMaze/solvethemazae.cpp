// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++

#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char grid[55][55] = {0};
bool visited[55][55] = {0};

void path(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '#')
        return;
    visited[i][j] = 1;
    for (int a = 0; a < 4; a++)
        path(i+dx[a], j+dy[a], n, m);
}

bool change(int i, int j, int n, int m)
{
    for (int a = 0; a < 4; a++) {
        int x = dx[a] + i, y = dy[a] + j;

        if (x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == '#')
            continue;
        if (grid[x][y] == 'G')
            return false;
        if (grid[x][y] == '.')
            grid[x][y] = '#';
    }
    return true;
}

bool solve(int n, int m)
{
    path(n-1, m-1, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G' && !visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main()
{
    setIO();
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        memset(grid, '.', sizeof(grid));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    if (!change(i, j, n, m)) {
                        works = false;
                        break;
                    }
                }
            }
        }
    
        if (!works) {
            cout << "No\n";
            continue;
        }

        works = solve(n, m);
        cout << (works ? "Yes\n" : "No\n");
    }

    return 0;
}