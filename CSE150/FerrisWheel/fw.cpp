// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

void solve()
{
    ;
}

int main()
{
    setIO();

    ll n, x; cin >> n >> x;

    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    ll l = 0, r = n-1;

    ll ans = 0;

    while(l < r) {
        if(arr[l] + arr[r] <= x) {
            ans++;
            l++;
            r--;
        }
        else
            r--;
    }

    cout << n - ans;

    return 0;
}