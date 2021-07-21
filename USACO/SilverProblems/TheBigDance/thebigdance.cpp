#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

ll ans = 0;

void go(vector<ll> v)
{
    const int sz = v.size();

    if (sz == 1)
        return;
    if (sz == 2) {
        ans += (v[0]*v[1]);
        return;
    }
    int mid = sz/2; 
    if (sz%2 == 1)
        mid++;
    go({v.begin(), v.begin()+mid});
    go({v.begin()+mid, v.end()});
}

int main()
{
    int n; cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        v[i] = i+1;

    go(v);

    cout << ans;

    return 0;
}
