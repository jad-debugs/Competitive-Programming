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
    // setIO("");

    int t; cin >> t;

    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        vector<int> ans;
        for (int i = 0, j = 0; i < n || j < m; ) {
            if (i >= n) {
                ans.push_back(b[j]);
                j++;
                continue;
            }
            else if (j >= m) {
                ans.push_back(a[i]);
                i++;
                continue;
            }
            if (a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        bool works = true;

        for (int x: ans) {
            if (x == 0)
                k++;
            else {
                if (x > k) {
                    works = false;
                    break;
                }
            }
        }
        if (!works) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < n+m-1; i++)
            cout << ans[i] << ' ';
        cout << ans[n+m-1] << '\n';
    }

    return 0;
}
