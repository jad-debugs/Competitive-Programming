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
    setIO("pairup");

    int n; cin >> n;

    pii arr[n];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }

    sort(arr, arr+n);

    int l = 0;
    int r = n-1;

    int ans = 0;

    while(l <= r) {
        ans = max(ans, arr[l].f + arr[r].f);

        int m = min(arr[l].s, arr[r].s);
        if(l == r)
            m /= 2;
        arr[l].s -= m;
        arr[r].s -= m;

        if(arr[l].s == 0)
            l++;
        if(arr[r].s == 0)
            r--;
    }
    cout << ans;
    return 0;
}
