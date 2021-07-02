#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<int> arr(n+1);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr[n] = 1000000001;

    // arr val, arr idx
    stack<pii> s;
    s.push({arr[0], 0});

    ll ans = 0;

    for (int i = 1; i < n+1; i++) {
        if (s.empty()) {
            s.push({arr[i], i});
            continue;
        }

        while (!s.empty() && s.top().f <= arr[i]) {
            ans += i - s.top().s-1;
            s.pop();
        }

        s.push({arr[i], i});
    }

    cout << ans;

    return 0;
}
