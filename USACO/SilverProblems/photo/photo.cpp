#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool cmp(pii a, pii b)
{
    if (a.s == b.s)
        return a.f < b.f;
    return a.s < b.s;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pii> pairs(k);

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        if (a > b)
            swap(a, b);
        pairs[i] = {a, b};
    }

    sort(pairs.begin(), pairs.end(), cmp);

    int last = 0, ans = 1; // 1 to account for last group
    for (int i = 0; i < k; i++) {
        if (pairs[i].f >= last) {
            ans++;
            last = pairs[i].s;
        }
    }

    cout << ans;

    return 0;
}
