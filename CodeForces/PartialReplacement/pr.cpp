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
        string s; cin >> s;

        int sz = s.size();
        int fp = n-1, lp = 0;

        for (int i = 0; i < sz; i++) {
            if (s[i] == '*') {
                fp = min(fp, i);
                lp = max(lp, i);
            }
        }

        int ans = 2;

        if (fp == lp) {
            cout << "1\n";
            continue;
        }

        int i = fp;
        while (i + k < lp) {
            int j = min(i+k, sz);

            for (; j > i; j--) {
                if (s[j] == '*') {
                    i = j;
                    s[j] = 'x';
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
