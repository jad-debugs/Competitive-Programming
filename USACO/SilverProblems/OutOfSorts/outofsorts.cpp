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
    setIO("sort");

    int n; cin >> n;

    vector<int> arr(n);
    multiset<int> tmp;
    map<int, int> map;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp.insert(arr[i]);
    }
    int i = 0;
    for (int x: tmp) {
        if (!map.count(x))
            map[x] = i;
        i++;
    }

    // only can move element to left one at a time.
    // right moves element to end, so it is not a contender unless pos

    int ans = 0;
    for (i = 0; i < n; i++) {
        ans = max(ans, i - map[arr[i]]);
        map[arr[i]]++;
    }

    cout << ans+1;
    return 0;
}
