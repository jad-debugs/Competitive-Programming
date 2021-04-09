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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n+1);

        for (int i = 1; i <= n; i++) {
            char x; cin >> x;
            arr[i] = x - '0' + arr[i-1];
        }
        unordered_map<int, int> scores;
        for (int i = 0; i <= n; i++)
            scores[arr[i] - i]++;
        ll ans = 0;
        for (auto x: scores) {
            ans += (ll)x.s*(x.s-1)/2;
        }
        cout << ans << '\n';
    } 
    return 0;
}
