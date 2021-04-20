#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string str; cin >> str;

    int q; cin >> q;
    while (q--) {
        int ans = 0;
        int m; cin >> m;
        char c; cin >> c;

        int r = 0, l = 0;
        for (; l < n && r < n; l++) {
            while (r < n) {
                if (str[r] != c) {
                    if (m == 0)
                        break;
                    m--;
                }

                r++;
            } 
            ans = max(ans, r - l);
            if (str[l] != c)
                m++;
        }       
        cout << ans << '\n';
    }
}

