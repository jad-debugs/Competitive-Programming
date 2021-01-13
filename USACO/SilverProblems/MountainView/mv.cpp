#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Peak {
    int x, y;

    bool blocked(Peak o) {
        if (x < o.x) {
            int diff = o.x - x;
            if(y + diff > o.y)
                return false;
        }
        else if(x > o.x) {
            int diff = x - o.x;
            if(y + diff > o.y)
                return false;
        }
        return true;
    }
};

bool cmp(Peak hi, Peak other) {
        if(other.x != hi.x) return hi.y < other.y;
        return hi.x < other.x;
}

int main() {
    setIO("mountains");
    int n; cin >> n; 

    Peak arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr+n, cmp);
    
    int ans = n;

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > i; j--) {
            ans -= arr[i].blocked(arr[j]);         
        }
    }
    cout << ans;
}
