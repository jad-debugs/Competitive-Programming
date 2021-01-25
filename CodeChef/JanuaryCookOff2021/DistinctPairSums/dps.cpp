#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t; cin >> t;

    while(t--) {
        long long a, b; cin >> a >> b;

        long long n = b-a + 1;

        long long ans = n+n-1;

        cout << ans << "\n";
    }

    return 0;
}