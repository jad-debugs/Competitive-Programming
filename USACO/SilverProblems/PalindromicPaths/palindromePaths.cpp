#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

char graph[19][19] = {0};
set<string> diag;
int n, ans = 0;

void go1(int r, int c, string path)
{
    if (r < 0 || r >= n || c < 0 || c >= n || r+c > n-1)
        return;
    path += graph[r][c];
    if (r + c == n-1) {
        diag.insert(path);
        return;
    }
    go1(r+1, c, path);
    go1(r, c+1, path);
}
void go2(int r, int c, string path)
{
    if (r < 0 || r >= n || c < 0 || c >= n || r+c < n-1)
        return;
    path += graph[r][c];
    if (r + c == n-1 && diag.find(path) != diag.end()) {
        ans++;
        diag.erase(path);
        return;
    }
    go2(r-1, c, path);
    go2(r, c-1, path);
}

int main()
{
    cin >> n;

    // she cant revist, its impossible

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    go1(0, 0, "");
    go2(n-1, n-1, "");

    cout << ans;

    return 0;
}
