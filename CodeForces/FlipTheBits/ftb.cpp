#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        a += "0";
        b += "0";
        int cnt = 0;
        bool sol = false;
        for (int i = 0; i < n; i++) {
            a[i] == '1' ? cnt += 1 : cnt -= 1;
            if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && cnt != 0) {
                cout << "NO\n";
                sol = true; 
                break;
            }
        }
        if (!sol)
            cout << "YES\n";
    }
}
