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

bool cmp(pii a, pii b)
{
    return a.s < b.s;
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
    setIO("helpcross");

    int c, n; cin >> c >> n;

    vector<int> chickens(c);
    vector<pii> cows(n);

    for (int i = 0; i < c; i++)
        cin >> chickens[i];
    for (int i = 0; i < n; i++)
        cin >> cows[i].f >> cows[i].s;

    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end(), cmp);
    
    int ans = 0;

    bool visited[n] = {0};

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            int cur = chickens[i];
            if (!visited[j] && cur >= cows[j].f && cur <= cows[j].s) {
                ans++;
                visited[j] = 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

