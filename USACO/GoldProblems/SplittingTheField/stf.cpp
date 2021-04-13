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

const int MX = 5e4+5;
int n;
vector<int> x(MX);
vector<int> y(MX);
vector<int> id(MX);

bool xcmp(int a, int b)
{
    if (x[a] == x[b])
        return y[a] < y[b];
    return x[a] < x[b];
}

bool ycmp(int a, int b)
{
    if (y[a] == y[b])
        return x[a] < x[b];
    return y[a] < y[b];
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
    setIO("split");

    cin >> n;
    multiset<int> lx, rx, ly, ry, allx, ally;

    for (int i = 0; i < n; i++) {
        id[i] = i;
        cin >> x[i]; cin >> y[i];
        allx.insert(x[i]);
        ally.insert(y[i]);
    }

    ll area = (ll)(*allx.rbegin() - *allx.begin())*(*ally.rbegin() - *ally.begin());
    sort(id.begin(), id.begin()+n, xcmp);

    rx = allx;
    ry = ally;

    ll Area2 = 1e18;

    // vertical sweep
    for (int i = 0; i < n; i++) {
        int idx = id[i];

        lx.insert(x[idx]);
        ly.insert(y[idx]);

        rx.erase(rx.find(x[idx]));
        ry.erase(ry.find(y[idx]));

        ll tmp2Area = (ll)(*lx.rbegin() - *lx.begin())*(*ly.rbegin() - *ly.begin());

        if (!rx.empty())
            tmp2Area += (ll)(*rx.rbegin() - *rx.begin())*(*ry.rbegin() - *ry.begin());
        Area2 = min(Area2, tmp2Area);
    }

    // horizontal sweep
    sort(id.begin(), id.begin()+n, ycmp);

    lx.clear();
    ly.clear();
    rx = allx;
    ry = ally;

    for (int i = 0; i < n; i++) {
        int idx = id[i];

        lx.insert(x[idx]);
        ly.insert(y[idx]);

        rx.erase(rx.find(x[idx]));
        ry.erase(ry.find(y[idx]));

        ll tmp2Area = (ll)(*lx.rbegin() - *lx.begin())*(*ly.rbegin() - *ly.begin());

        if (!rx.empty())
            tmp2Area += (ll)(*rx.rbegin() - *rx.begin())*(*ry.rbegin() - *ry.begin());
        Area2 = min(Area2, tmp2Area);
    }

    cout << area - Area2;
    return 0;
}
