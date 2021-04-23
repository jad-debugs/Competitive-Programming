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

const int MOD = 1e9+7;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main()
{
    setIO("");

    int n; cin >> n;

    int dp[n+1] = {1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            (dp[i] += dp[i-j])%=MOD;
        }
    }

    cout << dp[n];
    return 0;
}
