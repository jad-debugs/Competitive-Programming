// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    setIO("lemonade");

    int n; cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, cmp);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(ans > arr[i])
            break;
        ans++;
    }
    cout << ans;
    return 0;
}