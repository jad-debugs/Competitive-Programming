// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    int n;
    ll k, x; cin >> n >> k >> x;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<ll> diff;

    for (int i = 1; i < n; i++) {
        ll d = arr[i] - arr[i-1];
        if (d <= x)
            continue;
        diff.push_back(d);
    }

    sort(diff.begin(), diff.end());

    int ans = diff.size()+1;

    int i = 0;
    while (k > 0 && i < (int)diff.size()) {
        ll rm = ceil((long double)diff[i]/x) - 1;
        if (k - rm >= 0) {
            ans--;
            k -= rm;
        }
        i++;
    }

    cout << ans;

    return 0;
}
