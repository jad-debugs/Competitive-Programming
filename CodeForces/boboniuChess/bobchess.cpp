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

bool visited[100][100];
vector<pii> path;


int n, m, r, c;

void ff(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
        return;
    if ((int)path.size() == n*m)    
        return;

    visited[x][y] = 1;
    path.push_back({x+1, y+1});

    for (int i = 1; i < n; i++) {
        ff(x+i, y);
        ff(x-i, y);
    }
    for (int i = 1; i < m; i++) {
        ff(x, y+i);
        ff(x, y-i);
    }
}

int main()
{
    cin >> n >> m >> r >> c;
    r--; c--;

    ff(r, c);

    for (pii p: path)
        cout << p.f << ' ' << p.s << '\n';

    return 0;
}
