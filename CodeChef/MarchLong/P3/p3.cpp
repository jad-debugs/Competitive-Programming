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
        ll n; cin >> n;

        ll org[n];
        for (int i = 1; i <= n; i++) {
            org[i-1] = i;
        }

        ll sum = 0;

        bool done = false;
        ll main[n];

        for (int i = 0; i < n; i++)
            cin >> main[i];

        sort(main, main+n);

        for(int i = 0; i < n; i++) {
            if (main[i] > org[i]) {
                done = true;
                break;
            }
            else
                sum += org[i] - main[i];
        }
        
        if (sum%2 == 0 || done)
            cout << "Second\n";
        else
            cout << "First\n";
    }
    return 0;
}
