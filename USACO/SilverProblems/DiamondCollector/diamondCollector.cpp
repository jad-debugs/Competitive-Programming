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
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    //setIO("diamond");

    ll n, k; cin >> n >> k;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    ll idx1 = 0, idx2 = 0, big = 0;

    int cnt = 0;

    for (ll x: arr) {
        int tmp = upper_bound(cnt+arr.begin(), arr.end(), x+k) - arr.begin() - cnt;
        cnt++;
        if (tmp > big) {
            big = tmp;
            idx1 = cnt;
            idx2 = cnt+tmp-1;
        }
    }

    vector<ll> newA;

    for (int i = 0; i < n; i++) {
        if (i >= idx1 && i <= idx2)
            continue;
        newA.push_back(arr[i]);
    }
    ll small = 0; cnt = 0;
    for (ll x: newA) {
        ll tmp = upper_bound(cnt+newA.begin(), newA.end(), x+k) - newA.begin() - cnt;
        cnt++;
        small = max(tmp, small);
    }
    cout << big + small;
    return 0;
}
