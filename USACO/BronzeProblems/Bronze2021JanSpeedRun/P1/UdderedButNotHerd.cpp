// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

int main()
{
    setIO();

    string a; cin >> a;

    string w; cin >> w;

    int ans = 0;

    int letter = 0;

    const int sz = w.size();

    while(letter < sz) {
        bool f = false;
        for(int i = 0; i < 26; i++) {
            if(w[letter] == a[i]) {
                if(!f)
                    ans++;
                f = true;
                if(letter < sz - 1) {
                    letter++;
                }
                else {
                    letter++;
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}