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

const ll hi = 9e18;

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

    int n; cin >> n;
    ll first; cin >> first;
    ll arr[n] = {first};

    for (int i = 1; i < n; i++) {
        ll a; cin >> a;
        arr[i] = arr[i-1] + a;
    }

    ll minpf = 0, maxpf = -hi;
    for (int i = 0; i < n; i++) {
        maxpf = max(maxpf, arr[i] - minpf);
        minpf = min(minpf, arr[i]);
    }
    cout << maxpf;
    return 0;
}
