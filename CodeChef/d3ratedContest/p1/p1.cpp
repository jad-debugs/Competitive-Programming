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

    while(t--) {
        float m, h; cin >> m >> h;
        float bmi = m/h/h;
        if(bmi <= 18)
            cout << 1;
        else if(bmi <= 24)
            cout << 2;
        else if(bmi <= 29)
            cout << 3;
        else if(bmi >= 30)
            cout << 4;
        cout << "\n";
    }

    return 0;
}
