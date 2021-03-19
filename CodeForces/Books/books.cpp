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
    setIO("");

    ll books, time; cin >> books >> time;

    vector<int> arr(books+1);

    for (int i = 1; i <= books; i++) {
        int a; cin >> a;
        arr[i] = a + arr[i-1];
    }

    int ans = 0;

    for (int i = 0; i <= books; i++) {
        int tmp = upper_bound(arr.begin(), arr.end(), arr[i]+time) - arr.begin() - i - 1;
        ans = max(ans, tmp);
    }
    
    cout << ans;
    return 0;
}
