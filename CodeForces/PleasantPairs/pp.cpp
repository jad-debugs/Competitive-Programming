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

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> org(n);
        vector<int> arr(2*n+1, 1e6);

        for (int i = 0; i < n; i++) {
            cin >> org[i];
            arr[org[i]] = i+1;
        }

        int ans = 0;

        for (int i = 3; i < n*2; i++) {
            for (int j = 1; j*j < i; j++) {
                if (i%j == 0) {
                    if (arr[j] + arr[i/j] == i)
                        ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
