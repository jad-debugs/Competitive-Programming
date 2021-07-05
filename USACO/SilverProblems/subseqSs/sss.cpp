#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> pf(n+1);
    for (int i = 1; i <= n; i++) {
        pf[i] = (pf[i-1] + arr[i-1]%7)%7;
    }

    map<int, int> map;

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        if (map.find(pf[i]) == map.end())
            map[pf[i]] = i;
        else {
            ans = max(ans, i - map[pf[i]]);
        }
    }

    cout << ans;

    return 0;
}
