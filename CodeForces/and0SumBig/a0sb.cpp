#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long powM(long long a, long long b)
{
    long long ans = 1;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        ans %= mod;
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long a, b; cin >> a >> b;
        // must sum to 2^k - 1 (max)
        cout << powM(a, b) << '\n';
    }
}
