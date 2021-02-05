// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}


int main()
{
    setIO("div7");

    int n; cin >> n;

    int arr[n+1] = {0};

    int re[7] = {-1, -1, -1, -1, -1, -1, -1};

    int ans = -1;

    for(int i = 1; i < n+1; i++) {
        ll a; cin >> a;
        arr[i] = (arr[i-1] + a)%7;
        if(re[arr[i]] == -1) {
            re[arr[i]] = i;
        }
        else
            ans = max(ans, i - re[arr[i]]);
    }

    cout << ans;
    return 0;
}
