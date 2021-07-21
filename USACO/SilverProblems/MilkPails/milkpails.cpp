#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, m;
    cin >> x >> y >> k >> m;

    // -1 as not visted, otherwise represents length of path to it
    int sol[x+1][y+1];
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++)
            sol[i][j] = -1;
    }

    sol[0][0] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    int ans = 300;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (sol[curX][curY] > k)
            continue;

        ans = min(abs(m - (curX+curY)), ans);

        // try filling either bucket
        if (sol[x][curY] == -1) {
            q.push(make_pair(x, curY));
            sol[x][curY] = 1 + sol[curX][curY];
        }
        if (sol[curX][y] == -1) {
            q.push(make_pair(curX, y));
            sol[curX][y] = 1 + sol[curX][curY];
        }

        // try emptying either bucket
        if (sol[0][curY] == -1) {
            q.push(make_pair(0, curY));
            sol[0][curY] = 1 + sol[curX][curY];
        }
        if (sol[curX][0] == -1) {
            q.push(make_pair(curX, 0));
            sol[curX][0] = 1 + sol[curX][curY];
        }

        // pour one into other
        int diff = min(x-curX, curY);
        if (sol[curX+diff][curY-diff] == -1) {
            q.push(make_pair(curX+diff, curY-diff));
            sol[curX+diff][curY-diff] = 1 + sol[curX][curY];
        }
        diff = min(y - curY, curX);
        if (sol[curX-diff][curY+diff] == -1) {
            q.push(make_pair(curX-diff, curY+diff));
            sol[curX-diff][curY+diff] = 1 + sol[curX][curY];
        }
    }

    cout << ans;
}