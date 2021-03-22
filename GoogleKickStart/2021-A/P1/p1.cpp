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

    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        int n, k; cin >> n >> k;

        string tmp; cin >> tmp;

        int gs = 0;

        for (int i = 0; i < n/2; i++) {
            if (tmp[i] != tmp[n-1-i])
                gs++;
        }

        if (gs >= k)
            cout << gs - k;
        else
            cout << k - gs;

        cout << '\n';
    }

    return 0;
}
