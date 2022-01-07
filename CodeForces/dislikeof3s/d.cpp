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

    vector<int> v;

    for (int i = 1; i <= 100005; i++) {
        if (i%3==0)
            continue;
        if (i%10 == 3)
            continue;
        v.push_back(i);
    }

    while (t--) {
        int n; cin >> n;
        cout << v[n-1] << endl;
    }

    return 0;
}
