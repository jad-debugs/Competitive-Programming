#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<pair<int, int>> cows(n+1, {0, 0});
    vector<int> pf(n+1);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        char c; cin >> c;

        if (c == 'G')
            cows[i] = {a, 1};
        else if (c == 'H')
            cows[i] = {a, -1};
    }

    sort(cows.begin(), cows.end());

    int ans = 0;

    // accounting for continuous letter
    for (int i = 1, j = 1; i <= n && j <= n; ) {
        while (j <= n && cows[j].s == cows[i].s)
            j++;
        ans = max(cows[j-1].f-cows[i].f, ans);
        i = j;
    }

    for (int i = 1; i <= n; i++) {
        pf[i] = pf[i-1] + cows[i].s;
    }

    // fpos store cow after wher pf = pf
    map<int, int> fPos;

    // i corresponds to pf[i] in cow array.
    for (int i = 1; i <= n; i++) {
        if ((fPos.find(pf[i]) == fPos.end()) && i != n)
            fPos[pf[i]] = cows[i+1].f;
        else if (fPos.find(pf[i]) != fPos.end())
            ans = max(ans, cows[i].f - fPos[pf[i]]);
    }

    cout << ans;

    return 0;
}
