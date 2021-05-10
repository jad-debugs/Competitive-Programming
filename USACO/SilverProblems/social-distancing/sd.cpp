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

ll n, q;

bool solve(vector<pair<ll, ll>> coor, ll d)
{
    ll last = -1e18;
    ll cows = 0;
    for (int i = 0; i < q; i++) {
        ll cur = max(last+d, coor[i].f);
        if (cur > coor[i].s)
            continue;

        ll extra = (coor[i].s - cur)/d;
        cows += extra + 1;
        last = cur + extra*d;
    }
    return (cows >= n);
}

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("socdist");

    cin >> n >> q;

    vector<pair<ll, ll>> coor(q);

    for (int i  = 0; i < q; i++)
        cin >> coor[i].f >> coor[i].s;
    sort(begin(coor), end(coor));

    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = lo + (hi - lo+1)/2;
        if (solve(coor, mid))
            lo = mid;
        else
            hi = mid-1;
    }
    cout << lo << '\n';
    return 0;
}
