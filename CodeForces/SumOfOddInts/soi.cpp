#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        if (a%2 == b%2 && b*b <= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
