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
        int n, x; cin >> n >> x;
        set<int> distinct;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            distinct.insert(a);
        }
        
        cout << min((int)distinct.size(), n-x) << '\n';
    }

    return 0;
}
