#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<pii> v(n);
    vector<int> mx(n);
    vector<int> mn(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    sort(begin(v), end(v));

    mx[n-1] = v[n-1].s;
    mn[0] = v[0].s;

    for (int i = 1; i < n; i++) {
        mn[i] = min(mn[i-1], v[i].s);
    }
    for (int i = n-2; i >= 0; i--) {
        mx[i] = max(mx[i+1], v[i].s);
    }

    int cc = 1;

    for (int i = 0; i < n-1; i++) {
        if (mn[i] > mx[i+1]) {
            cc++;
        }
    }

    cout << cc;

    return 0;
}
