#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, k; cin >> n >> t >> k;

    int l = 1, r = n;
    while (l < r) {

        int m = (l+r)/2;

        cout << "? " << l << " " << m << endl;

        int ones;
        cin >> ones;
        if (ones == -1) {
            cout << "exited" << endl;
            exit(0);
        }
        int zeros = (m - l + 1) - ones;

        if (zeros >= k)
            r = m;
        else {
            k -= zeros;
            l = m+1;
        }
    }
    cout << "! " << l << endl;

    return 0;
}