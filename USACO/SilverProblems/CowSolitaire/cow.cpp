#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int grid[8][8] = {0};
int ans = 0, n;

void go(int r, int c, int sum, int moves)
{
    if (r < 0 || r >= n || c < 0 || c >= n || moves > n*2-2)
        return;
    if (r == 0 && c == n-1) {
        ans = max(ans, sum+grid[r][c]);
    }
    go(r-1, c, sum+grid[r][c], moves+1);
    go(r, c+1, sum+grid[r][c], moves+1);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string str; cin >> str;
            char c = str[0];
            if (c == 'A') {
                grid[i][j] = 1;
                continue;
            }
            if (c == 'T') {
                grid[i][j] = 10;
                continue;
            }
            if (c == 'J') {
                grid[i][j] = 11;
                continue;
            }
            if (c == 'Q') {
                grid[i][j] = 12;
                continue;
            }
            if (c == 'K') {
                grid[i][j] = 13;
                continue;
            }
            grid[i][j] = c - '0';
        }
    }

    go(n-1, 0, 0, 0);

    cout << ans;

    return 0;
}
