#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr(n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] <= 0)
                ans++;
        }

        sort(arr.begin(), arr.end());
        int mnP = 1e9+10;

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0)
                mnP = min(mnP, arr[i]);
        }

        bool flag = (mnP < 1e9+10);

        for (int i = 1; i < n; i++) {
            if (arr[i] <= 0) {
                flag = (arr[i] - arr[i-1] >= mnP);
                if (flag == false)
                    break;
            }
        }

        if (flag)
            cout << ans+1 << '\n';
        else
            cout << ans << '\n';
    }
}