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

    int a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 0; i <= a; i++) {
        int t1 = a - i;
        int t2 = b-2*i;
        if (t2 >= 0) {
            ans = max(ans, min(t2, t1/2)+i);
        }
    }
    cout << ans;
    return 0;
}
