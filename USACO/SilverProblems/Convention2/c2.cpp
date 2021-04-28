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

struct cow
{
    int id, start, duration;
};

bool cmp(cow a, cow b)
{
    return a.start < b.start;
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
    setIO("convention2");


    int n; cin >> n;

    vector<cow> cows(n);

    for (int i = 0; i < n; i++) {
        cows[i].id = i;
        cin >> cows[i].start >> cows[i].duration;
    }
    sort(cows.begin(), cows.end(), cmp);

    // .f = id, .s = cow idx
    multiset<pii> wait;

    int ans = 0, idx = 1, time = cows[0].start + cows[0].duration;

    while (idx < n || wait.size() > 0) {
        while (idx < n && cows[idx].start <= time) {
            wait.insert({cows[idx].id, idx});
            idx++;
        }
        if (wait.size() > 0) {
            auto priority = wait.begin();
            ans = max(ans, time - cows[priority->s].start);
            time += cows[priority->s].duration;
            wait.erase(priority);
        }
        else if (idx < n) {
            time = cows[idx].start + cows[idx].duration;
            idx++;
        }
    }

    cout << ans;

    return 0;
}
