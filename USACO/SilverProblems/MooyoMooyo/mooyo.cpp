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

int n, k;
int mat[101][11];
int visited[101][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cnt = 0;

void ff(int r, int c, int color)
{
    visited[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || mat[r2][c2] != mat[r][c] || visited[r2][c2] == color)
            continue;
        ff(r2, c2, color);
        cnt++;
    }
}

void makeZero(int r, int c, int color, int prev)
{
    visited[r][c] = color;
    mat[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || mat[r2][c2] != prev || visited[r2][c2] == color)
            continue;
        makeZero(r2, c2, color, prev);
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

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)
            cin >> mat[i][j];
    }

    int color = 1;
    int color2 = 1;

    vector<int> offset(10);

    int x = 100;

    while (/*true*/ x < 100) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                ff(i, j, color);
                if (cnt >= k) {
                    found = true;
                    makeZero(i, j, ++color2, mat[i][j]);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                if (mat[i][j] == 0)
                    break;

                int z = i;
                for (; z < n-1; z++)
                    if (mat[z+1][j] != 0)
                        break;
                mat[z][j] = mat[i][j];
                mat[i][j] = 0;
            }
        }

        color++;
        cnt = 0;
        if (!found)
            break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)
            cout << mat[i][j];
        cout << "\n";
    }

    return 0;
}
