#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int graph[5][5] = {0};
set<int> s;

void go(int itr, int r, int c, int num)
{
    if (r < 0 || r >= 5 || c < 0 || c >= 5)
        return;
    if (itr >= 6) {
        s.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int r2 = r+dx[i];
        int c2 = c+dy[i];
        if (r2 < 0 || r2 >= 5 || c2 < 0 || c2 >= 5)
            continue;
        go(itr+1, r2, c2, 10*num+graph[r2][c2]);
    }
}

int main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> graph[i][j];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            go(0, i, j, 0);
        }
    }

    cout << s.size();

    return 0;
}
