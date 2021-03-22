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

    pair<int, int> arr[n];

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        int b; cin >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr+n);

    long long right = 0;
    long long ans = 0;

    for(pair<int, int> m : arr) {
        right += m.first;
        ans += m.second - right;
    }
    cout << ans;
    return 0;
}