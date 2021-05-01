#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n+2);

        for (int i = 0; i < n+2; i++) {
            cin >> arr[i];
        }
        sort(begin(arr), end(arr));

        long long pf = 0;
        for (int i = 0; i < n; i++) {
            pf += arr[i];
        }
        if (pf == arr[n]) {
            for (int i = 0; i < n; i++) {
                cout << arr[i];
                if (i != n-1)
                    cout << ' ';
            }
            cout << '\n';
            continue;
        }
        pf += arr[n];
        long long look = pf - arr[n+1];
        vector<int> ans;
        bool sol = false;

        for (int i = 0; i < n+1; i++) {
            if (arr[i] == look && !sol) {
                sol = true;
            }
            else {
                ans.push_back(arr[i]);
            }
        }
        if (sol) {
            for (int i = 0; i < n; i++) {
                cout << ans[i];
                if (i != n-1)
                    cout << ' ';
            }
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
}
