#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<int> speeds(n);

    for (int i = 0; i < n; i++) {
        int garbo;
        cin >> garbo >> speeds[i];
    }

    int curS = speeds[n-1], ans = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (speeds[i] <= curS) {
            ans++;
            curS = speeds[i];
        }
    }

    cout << ans;

    return 0;
}
