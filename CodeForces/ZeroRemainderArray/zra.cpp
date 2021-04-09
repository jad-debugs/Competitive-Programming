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
    while (t--) {
        int n, k; cin >> n >> k;
        int curDone = 0;
        map<ll, ll> map;

        ll most = 0;
        ll mostIdx = 0;

        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            if (a%k==0)
                curDone++;
            else {
                if (++map[k - a%k] > most) {
                    most = map[k - a%k];
                    mostIdx = (k - a%k);
                }
                else if (map[k - a%k] == most) {
                    if (k-a%k > mostIdx)
                        mostIdx = k-a%k;
                }
            }
        }
        if (curDone == n) {
            cout << "0\n";
            continue;
        }
        cout << ((most-1)*k + mostIdx+1) << '\n';
    }

    return 0;
}
