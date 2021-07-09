#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int bales[20] = {0};
bool dp[850][850][20] = {0};
int n, res = 750, a = 0, b = 0, c = 0;

void go(int i)
{
    if (i >= n) {
        int maxVal = max(a, max(b, c));
        res = min(res, maxVal);
        return;
    }
    // bales[i] goes to A
    if (!dp[a+bales[i]][b][i] && a + bales[i] < res) {
        a += bales[i];
        dp[a][b][i] = dp[b][a][i] = 1;
        go(i+1);
        dp[a][b][i] = dp[b][a][i] = 0;
        a -= bales[i];
    }
    // bales[i] goes to B
    if (!dp[a][b+bales[i]][i] && b + bales[i] < res) {
        b += bales[i];
        dp[a][b][i] = dp[b][a][i] = 1;
        go(i+1);
        dp[a][b][i] = dp[b][a][i] = 0;
        b -= bales[i];
    }
    // bales[i] goes to C
    if (!dp[a][b][i] && c + bales[i] < res) {
        c += bales[i];
        dp[a][b][i] = dp[b][a][i] = 1;
        go(i+1);
        dp[a][b][i] = dp[b][a][i] = 0;
        c -= bales[i];
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> bales[i];

    go(0);

    cout << res;

    return 0;
}
