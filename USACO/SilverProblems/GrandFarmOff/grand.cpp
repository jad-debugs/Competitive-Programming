#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, a, b, c, d, e, f, g, h, m;

ll weight(int i)
{
    ll k = i%d; 
    ll tmpA = k, tmpB = k;

    for (int i = 0; i < 4; i++) {
        tmpA *= k;
        tmpA %= d;
    }
    tmpA *= (a%d);
    tmpA %= d;

    tmpB *= k;
    tmpB %= d;
    tmpB *= (b%d);
    tmpB %= d;

    ll ans = tmpA + tmpB + c%d;
    ans %= d;
    return ans;
}

ll utility(int i)
{
    ll k = i%h, tmpE = k, tmpF = k;
    for (int i = 0; i < 4; i++) {
        tmpE *= k;
        tmpE %= h;
    }
    tmpE *= (e%h);
    tmpE %= h;

    for (int i = 0; i < 2; i++) {
        tmpF *= k;
        tmpF %= h;
    }
    tmpF *= (f%h);
    tmpF %= h;

    ll ans = tmpE + tmpF + g%h;
    ans %= h;
    return ans;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;

    vector<pair<ll, ll>> cows(3*n);

    for (int i = 0; i < 3*n; i++) {
        cows[i] = {utility(i), weight(i)};
    }

    sort(cows.begin(), cows.end(), cmp);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += cows[i].second%m;
    }

    cout << ans%m;

    return 0;
}
