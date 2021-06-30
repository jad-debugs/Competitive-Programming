#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, b; cin >> n >> k >> b;

    vector<int> val(n+1);

    for (int i = 0; i < b; i++) {
        int a; cin >> a;
        val[a] = 1;
    }

    vector<int> pf(n+1);

    for (int i = 1; i <= n; i++)
        pf[i] = pf[i-1] + val[i];

    int ans = k;
    for (int i = k; i <= n; i++)
        ans = min(ans, pf[i] - pf[i-k]);

    cout << ans;

    return 0;
}
