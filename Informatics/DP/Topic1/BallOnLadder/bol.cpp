#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[36] = {0};

ll steps(ll n)
{
    if (dp[n])
        return dp[n];
    if (n == 0)
        return 1;
    dp[n] = steps(n-2) + steps(n-1);
    return dp[n];
}

int main()
{
    ll n; cin >> n;
    cout << steps(7);
}