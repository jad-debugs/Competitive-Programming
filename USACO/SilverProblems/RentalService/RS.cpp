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
    if (a.s == b.s)
        return a.f > b.f;
    return a.s > b.s;
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
    setIO("rental");

    int n, m, r; cin >> n >> m >> r;

    vector<int> gallons(n);
    for (int i = 0; i < n; i++)
        cin >> gallons[i];
    sort(gallons.begin(), gallons.end(), greater<int>());
    vector<pii> rent(m);

    for (int i = 0; i < m; i++)
        cin >> rent[i].f >> rent[i].s;
    sort(rent.begin(), rent.end(), cmp);

    vector<int> sell(r);
    for (int i = 0; i < r; i++)
        cin >> sell[i];
    sort(sell.begin(), sell.end());

    int firstSell = r - n;

    int cur = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll soldPrice = 0;
        if (firstSell >= 0)
            soldPrice = sell[firstSell];
        firstSell++;
        ll rentPrice = 0;
        while (cur < m) {
            int tmp = min(gallons[i], rent[cur].f);
            rentPrice += rent[cur].s*tmp;
            gallons[i] -= tmp;
            rent[cur].f -= tmp;
            if (gallons[i] <= 0)
                break;
            else
                cur++;
        }
        ans += max(soldPrice, rentPrice);

        if (soldPrice > rentPrice) {
            for (; firstSell < r; firstSell++)
                ans += sell[firstSell];
            break;
        }
    }

    cout << ans;
    return 0;
}
