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
        string str; cin >> str;
        const int n = str.size();

        pii i01 = {0, 0};

        for (int i = 0; i < n; i++) {
            if (str[i] == '0')
                i01.f++;
            else
                i01.s++;
        }

        pii s01 = {0, 0};
        int ans = min(i01.f, i01.s);
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                s01.f++;
                i01.f--;
            }
            else {
                s01.s++;
                i01.s--; 
            }
            ans = min(ans, i01.f + s01.s);
            ans = min(ans, i01.s + s01.f);
        }
        cout << ans << '\n';
    }
    return 0;
}
