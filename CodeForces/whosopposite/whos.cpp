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
    //setIO("");

    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int diff = max(a, b) - min(a, b);
        int tot = diff*2;
        if (max(a,max(b, c)) > tot)
            cout << -1 << "\n";
        else if (tot >= diff+c)
            cout << diff+c << endl;
        else if (1 <= abs(diff-c))
            cout << abs(diff-c) << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
