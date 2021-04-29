#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, f; cin >> n >> f;
        vector<int> arr(n);
        vector<int> friends(f);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < f; i++)
            cin >> friends[i];
        sort(arr.begin(), arr.end());
        sort(friends.begin(), friends.end());
        
        int c1 = 0, l = 0, r = n-1;
        long long ans = 0;
        for (int i = 0; i < f; i++) {
            if (friends[i] != 1)
                break;
            else {
                ans += 2*arr[n-c1-1];
                c1++;
                r--;
            }
        }

        for (int i = f-1; i >= c1;i--) {
            ans += arr[r]; r--;
            ans += arr[l];
            l += friends[i]-1;
        }
        cout << ans << '\n';
    }
}
