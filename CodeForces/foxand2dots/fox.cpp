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

const int dim = 55;

char graph[dim][dim];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[dim][dim];

bool done = false;

void ff(int fromX, int fromY, int toX, int toY, char color)
{
    if (visited[toX][toY]) {
        done = true;
        return;
    }
    visited[toX][toY] = 1;

    for (int i = 0; i < 4; i++) {
        int x = toX + dx[i];
        int y = toY + dy[i];

        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if (fromX == x && fromY == y)
            continue;
        if (color == graph[x][y])
            ff(toX, toY, x, y, color);
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

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j])
                ff(-1, -1, i, j, graph[i][j]);
            if (done) {
                cout << "Yes\n";
                return 0;
            }
        }
    }


    cout << "No\n";

    return 0;
}
