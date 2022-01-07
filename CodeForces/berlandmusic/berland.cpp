#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            cin >> ans[i];

        vector<pair<int, int> > bad, good;

        int liked = 0;

        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == '0')
                bad.push_back(make_pair(ans[i], i));
            else {
                liked++;
                good.push_back(make_pair(ans[i], i));
            }
        }

        sort(bad.begin(), bad.end());
        sort(good.begin(), good.end());

        int cnt = 0;

        for (int i = 1; i <= n-liked; i++) {
            ans[bad[cnt].second] = i;
            cnt++;
        }
        cnt = 0;
        for (int i = n-liked+1; i <= n; i++) {
            ans[good[cnt].second] = i;
            cnt++;
        }

        for (int i = 0; i < n-1; i++)
            cout << ans[i] << ' ';
        cout << ans[n-1] << "\n";
    }
}