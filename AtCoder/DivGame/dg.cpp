#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n; cin >> n;
    int ans = 0;
    for (ll i = 2; i*i <= n; i++) {
        int exp_ = 0;
        // count size of exponent in prime factor
        while (n % i == 0) {
            exp_++;
            n /= i;
        }
        for (int i = 1; exp_ - i >= 0; i++) {
            exp_ -= i;
            ans++;
        }
    }
    if (n > 1)
        ans++;
    cout << ans << '\n';
}
