/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

struct lf {
    int l, r;

};

bool cmp(lf a, lf o) {
        if(a.l == o.l) return a.r < o.r;
        return a.l < o.l;
}


void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("lifeguards");

    int n; cin >> n;

    lf lifeguards[n];

    for(int i = 0; i < n; i++) {
        cin >> lifeguards[i].l >> lifeguards[i].r;
    }
    
    int totalTime = 0, left = 0, right = 0;
    
    sort(lifeguards, lifeguards + n, cmp);

    for(auto u : lifeguards) {
        if(u.r > right) {
            left = max(right, u.l);
            right = u.r;
            totalTime += right - left;
        } 
    }
    int low = 1e9+1;
    right = 0;

    for(int i = 0; i < n; i++) {
        int cur;
        if(i == n-1)
            cur = lifeguards[i].r - max(right, lifeguards[i].l); 
        else
            cur = min(lifeguards[i+1].l, lifeguards[i].r) - max(right, lifeguards[i].l); 
        low = min(low, cur);
        right = max(right, lifeguards[i].r);
    }
    
    if(low < 0) low = 0;
    cout << totalTime - low;
}
