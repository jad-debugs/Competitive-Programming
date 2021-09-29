#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    // take prefix sums and get amount made from each point using upper bound - 1

    vector<int> value(n);

    vector<long long> pf(n+1);

    for (int i = 1; i <= n; i++) {
        value[i-1] = v[i-1].first;
        pf[i] = pf[i-1] + v[i-1].second;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        auto tmp = upper_bound(value.begin(), value.end(), value[i]+d-1);
        tmp--;
        
        int last = tmp - value.begin();

        ans = max(ans, pf[last+1] - pf[i]);
    }

    cout << ans;

}