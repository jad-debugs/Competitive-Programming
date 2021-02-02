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

    multiset<int> towers;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for(int i: arr) {
        auto it = towers.upper_bound(i);
        if(it == towers.end()) {
            ans++;
            towers.insert(i);
        }     

        else {
            towers.erase(it);
            towers.insert(i);
        }
    }

    cout << ans;

    return 0;
}