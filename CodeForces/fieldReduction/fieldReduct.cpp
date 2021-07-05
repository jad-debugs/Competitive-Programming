#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool cmp(pair<pii, int> a, pair<pii, int> b)
{
    return a.f.s < b.f.s;
}

int main()
{
    int n; cin >> n;

    // .f is point, .f.f = x, .f.s = y, .s = id
    vector<int> x(n);
    vector<int> y(n);
    vector<pii> org(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
        org[i] = {x[i], y[i]};
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int ans = 2e9;

    for (int i = 0; i < min(n, 4); i++) {
        for (int j = max(n-4, 0); j < n; j++) {
            for (int a = 0; a < min(n, 4); a++) {
                for (int b = max(0, n-4); b < n; b++) {
                    int cnt = 0;
                    for (int k = 0; k < n; k++) {
                        int xpos = org[k].f;
                        int ypos = org[k].s;
                        if (xpos >= x[i] && xpos <= x[j] && ypos >= y[a] && ypos <= y[b])
                            cnt++;
                        if (cnt >= n-3) {
                            ans = min(ans, (abs(x[j]-x[i]))*(abs(y[b]-y[a])));
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
