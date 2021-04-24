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
    setIO("diamond");

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> maxHold(n);

    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && arr[r] - arr[l] <= k)
            r++;
        maxHold[l] = r-l;
    }

    vector<int> maxHoldSuffix(n+1);
    int curMx = 0;

    for (int i = n-1; i >= 0; i--) {
        curMx = max(maxHold[i], curMx);
        maxHoldSuffix[i] = curMx;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, maxHold[i] + maxHoldSuffix[maxHold[i]+i]);

    cout << ans;
    return 0;
}
