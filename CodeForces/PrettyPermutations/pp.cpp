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

        if (n%2 == 0) {
            for (int i = 2; i <= n-2; i+=2) {
                cout << i << ' ' << i - 1 << ' ';
            }
            cout << n << ' ' << n-1;
        }
        else {
            int ev = n-3;
            for (int i = 2; i <= ev; i += 2)
                cout << i << ' ' << i - 1 << ' ';
            cout << n << ' ' << n-2 << ' ' << n-1;
        }
        cout << '\n';
    }

    return 0;
}
