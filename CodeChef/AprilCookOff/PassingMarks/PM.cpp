#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int as, bs, cs, ts, a, b, c;
        cin >> as >> bs >> cs >> ts >> a >> b >> c;
        if (a < as || b < bs || c < cs || a+b+c < ts)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
}

