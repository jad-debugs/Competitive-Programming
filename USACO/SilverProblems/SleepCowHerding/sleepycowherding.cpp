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
    setIO("herding");

    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    // min
    // if n-1 consecutive, ans = 2
    if (arr[n-2] - arr[0] == n-2 && arr[n-1] - arr[n-2] > 2)
        cout << 2 << '\n';
    else if (arr[n-1] - arr[1] == n-2 && arr[1] - arr[0] > 2)
        cout << 2 << '\n';
    else {
        int l = 0, r = 0, ans = 0;
        for (; l < n; l++) {
            while (r + 1 < n && arr[r+1] - arr[l] < n)
                r++;
            ans = max(ans, r - l + 1);
        }
        cout << n - ans << '\n';
    } 
    // max
    cout << (arr[n-1] - arr[0] - min(arr[n-1] - arr[n-2], arr[1] - arr[0]) - n + 2);

    return 0;
}
