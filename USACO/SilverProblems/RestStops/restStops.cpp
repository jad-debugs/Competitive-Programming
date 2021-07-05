#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    ll l, n, f, b; cin >> l >> n >> f >> b;

    ll d = f - b;

    priority_queue<pair<ll, ll>> pq;

    for (int i = 0; i < n; i++) {
        int x, c; cin >> x >> c;
        pq.push({c, x});
    }

    ll ans = 0;
    ll pos = 0;

    while (!pq.empty()) {
        if (pq.top().s <= pos)
            pq.pop();
        else {
            ans += (pq.top().s - pos)*d*pq.top().f;
            pos = pq.top().s;
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}
