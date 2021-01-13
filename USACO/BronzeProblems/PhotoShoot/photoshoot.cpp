/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int check(int n, int arr[]) {
    set<int> set;

    for(int i = 0; i < n; i++) {
        if(arr[i] <= n && arr[i] >= 1) {
            if(set.count(arr[i]) == 1)
                return 0;
            set.insert(arr[i]);
        }
        else
            return 0;
    }
    for(int i = 0; i < n-1; i++)
        cout << arr[i] << " ";
    cout << arr[n-1];
    return 1;
}

void setIO(string name = "photo") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

    int n; cin >> n;

    int arrIN[n-1];

    for(int i = 0; i < n-1; i++) {
        cin >> arrIN[i];
    }

    int ans[n];

    for(int guess = 1; guess <= n; guess++) {
        ans[0] = guess;
        for(int re = 1; re < n; re++) {
            ans[re] = arrIN[re-1] - ans[re-1];
        }
        if(check(n, ans)) {
            return 0;
        }
    }
    return 0;
}
