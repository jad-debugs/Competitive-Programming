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

struct cow {
    int time, id, change;
};

bool cmp(cow a, cow b)
{
    return a.time < b.time;
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
    setIO("measurement");

    int n, g; cin >> n >> g; // no need for g, just imagine its 0

    vector<cow> cows(n);
    map<int, int> cowGallon; // id -> gallons
    map<int, int> gallons; // cows with gallon size

    gallons[0] = 0; // index errors, dud

    for (int i = 0; i < n; i++)
        cin >> cows[i].time >> cows[i].id >> cows[i].change;
    sort(cows.begin(), cows.end(), cmp);

    int ans = 0;
    for (cow cur: cows) {
        bool wasMx = cowGallon[cur.id] == gallons.rbegin()->f;
        int oldCnt = gallons[cowGallon[cur.id]]--; // wont be zero, so its changing from here

        if (oldCnt == 1)
            gallons.erase(cowGallon[cur.id]);

        cowGallon[cur.id] += cur.change;

        int newCnt = ++gallons[cowGallon[cur.id]];
        bool isMx = cowGallon[cur.id] == gallons.rbegin()->f;

        if ((wasMx && !isMx) || (!wasMx && isMx) || (wasMx && isMx && (oldCnt != 1 || newCnt != 1)))
            ans++;
    }

    cout << ans;
    return 0;
}
