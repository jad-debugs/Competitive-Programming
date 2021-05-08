#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, mod; cin >> n >> mod;
        map<int, int> map;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            map[a%mod]++;
        }
        int ans = (map[0] > 0 ? 1: 0);
        map[0] = 0;
        for (auto pii: map) {
            if (pii.second == 0)
                continue;
            else if (abs(pii.second - map[mod - pii.first]) <= 1)
                ans++;
            else {
                ans += abs(pii.second - map[mod - pii.first]);
            }
            map[mod-pii.first] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}
