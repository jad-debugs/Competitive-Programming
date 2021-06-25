#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<int> factors;

        for (long long i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                factors.push_back(i);
                if (!(n/i == i)) {
                    factors.push_back(n/i);
                }
            }
        }

        long long ans = 2e16;
        for (long long x: factors) {
            if (x > k)
                continue;
            ans = min(n/x, ans);
        }

        cout << ans << '\n';
    }
    return 0;
}