#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

const ll inf = 1e15;

int main()
{
    int n;
    ll a, b; cin >> n >> a >> b;

    vector<pair<int, bool>> cows(n, {0, false});

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        if (str == "S")
            cows[i].s = 1;
        else
            cows[i].s = 0;
        cin >> cows[i].f;
    }

    cows.push_back({-inf, 0});
    cows.push_back({inf, 0});

    sort(cows.begin(), cows.end());

    ll ans = 0;

    for (int i = 0; i < n+1; i++) {
        ll fr = cows[i].f;
        ll br = cows[i+1].f;
        ll mid = (fr+br)/2;

        if (cows[i].s) {
            ll start = max(a, fr+1);
            ll end = min(b, mid);
            ans += max(0LL, end-start+1);
        }
        if (cows[i+1].s) {
            ll start = max(a, mid+1);
            ll end = min(b, br);
            ans += max(0LL, end-start+1);
        }
        // in middle
        if (!cows[i].s && cows[i+1].s && (fr%2) == (br%2) && a <= mid && mid <= b)
            ans++;
    }

    cout << ans;

    return 0;
}