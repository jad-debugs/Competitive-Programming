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

    int stick, n; cin >> stick >> n;
    ll ans = 0;

    // sort or pq, ill use pq to practice with it and may be faster than sorting

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pq.push(a);
    }

    for (int i = 1; i < n; i++) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        ans += a+b;
    }
    cout << ans;
    return 0;
}
