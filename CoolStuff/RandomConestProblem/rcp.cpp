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

    for (int T = 1; T <= t; T++) {
        int n; cin >> n;
        int arr[n];
        int small = (int)2e6;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            small = min(small, arr[i]);
        }
        ll ans = 1;

        for (int i = 2; i <= small; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (arr[j]%i) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        cout << "Case #" << T << ' ' << ans << "\n";
    }
    return 0;
}
