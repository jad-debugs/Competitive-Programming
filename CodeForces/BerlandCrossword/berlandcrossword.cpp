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
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int t; cin >> t;

    while(t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;

        // up cases
        if (r >= 1) {
            r--;
            if (u == n) {
                if (l >= 1)
                    l--;
                else {
                    cout << "No\n";
                    continue;
                }
            }
            u = 0;
        }
        else if (l >= 1) {
            l--;
            if (u == n) {
                cout << "No\n";
                continue;
            }
            u = 0;
        }
        else {
            if (u > n -2) {
                cout << "No\n";
                continue;
            }
            u = 0;
        }

        // down cases
        if (l >= 1) {
            l--;
            if(l == n) {
                if(r >= 1)
                    r--;
                else {
                    cout << "No";
                    continue;
                }
            }
            d = 0;
        }
        else if (r >= 1) {
            r--;
            if (d == n) {
                cout << "No\n";
                continue;
            }
            d = 0;
        }
        else {
            if (d > n - 2) {
                cout << "No\n";
                continue;
            }
            d = 0;
        }

        cout << "Yes\n";
    }

    return 0;
}
