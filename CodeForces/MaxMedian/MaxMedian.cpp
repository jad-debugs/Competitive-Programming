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

    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 1, right = 3e5;

    vector<int> pf(n);

    while (left < right) {
        int mid = (left + right+1)/2; // wont overflow

        for (int i = 0; i < n; i++) {
            if (arr[i] < mid)
                pf[i] = -1;
            else
                pf[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            pf[i] += pf[i-1];
        }

        int mx = pf[k-1], mn = 0;

        for (int i = 0; i < n-k; i++) {
            mn = min(mn, pf[i]);
            mx = max(mx, pf[i+k] - mn);
        }

        if (mx > 0)
            left = mid;
        else
            right = mid-1;
    }

    cout << left;

    return 0;
}
