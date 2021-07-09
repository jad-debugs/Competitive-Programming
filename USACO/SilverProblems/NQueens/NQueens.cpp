#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int ans = 0, n;
int col[50] = {0};
int diag1[50] = {0};
int diag2[50] = {0};

void solve(int x)
{
    if (x == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (col[i] || diag1[x+i] || diag2[i-x+n-1])
            continue;
        col[i] = 1;
        diag1[i+x] = 1;
        diag2[i-x+n-1] = 1;
        solve(x+1); // next piece
        // back track
        col[i] = 0;
        diag1[i+x] = 0;
        diag2[i-x+n-1] = 0;
    }
}

int main()
{
    cin >> n;

    solve(0);

    cout << ans;

    return 0;
}
