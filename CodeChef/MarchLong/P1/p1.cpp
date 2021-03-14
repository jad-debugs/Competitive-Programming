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
        string s; cin >> s;
        int sz = s.length();
        int groups = 0;
        bool isOne = false;
        for(int i = 0; i < sz; i++) {
            if (s[i] == '1' && !isOne) {
                groups++;
                isOne = true;
            }
            else if (s[i] == '0')
                isOne = false;
        }
        cout << groups << "\n";
    }

    return 0;
}
