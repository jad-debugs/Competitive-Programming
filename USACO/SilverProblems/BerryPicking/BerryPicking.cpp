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

int n, k, mx = 0;

int solve(int x, vector<int> berries)
{
    vector<int> pos(mx+1);
    for (int i = 0; i < n; i++) {
        pos[x] += berries[i]/x;
        pos[berries[i]%x]++;
    }
    int recieved = 0;
    int given = 0;
    int tot = 0;
    for (int i = mx; i >= 1; i--) {
        if (!pos[i])
            continue;
        if (given < k/2) {
            int tmp = min(k/2-given, pos[i]);
            given += tmp;
            pos[i] -= tmp;
        }
        if (given >= k/2) {
            int tmp = min(k/2 - recieved, pos[i]);
            pos[i] -= tmp;
            recieved += tmp;
            tot += i*tmp;
        }
        if (recieved >= k/2)
            break;
    }
    return tot;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("berries");

    cin >> n >> k;

    vector<int> berries(n);
    for (int i = 0; i < n; i++) {
        cin >> berries[i];
        mx = max(mx, berries[i]);
    }

    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans = max(solve(i, berries), ans);
    }

    cout << ans;
    return 0;
}
