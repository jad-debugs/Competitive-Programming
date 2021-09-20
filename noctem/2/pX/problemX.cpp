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
    setIO("whitejack");

    int n, m, k, q; cin >> n >> m >> k >> q;

    map<int, int> map;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[k-a]++;
    }

    set<int> set;

    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        if (map[a] >= 1)
            set.insert(i);
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;

        auto p = set.lower_bound(a);

        if (p == set.end())
            cout << "NO\n";
        else if (*p <= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    return 0;
}
