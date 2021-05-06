#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int ans = 0;
        if (x == 1)
            ans = 1;
        else
            ans = 2;
        for (int i = 2; i*i <= x; i++) {
            if (i*i == x)
                ans++;
            else if (x % i == 0)
                ans += 2;
        }
        cout << ans << '\n';
    }
}
