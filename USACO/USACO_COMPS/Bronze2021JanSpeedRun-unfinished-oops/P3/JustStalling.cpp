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

    int n; cin >> n;

    int h[n], bar[n], pf[n] = {0};

    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        cin >> bar[i];

    int j = 0;

    sort(h, h+n);
    sort(bar, bar+n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(bar[i] >= h[j]) {
                pf[i]++;
            }
        }
    }

    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans *= (pf[i]-i);
    }

    cout << ans;
    return 0;
}