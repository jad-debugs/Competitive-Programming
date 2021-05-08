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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("haybales");

    int n, q; cin >> n >> q;
    vector<int> haybales(n);

    for (int i = 0; i < n; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        auto up = upper_bound(haybales.begin(), haybales.end(), b);
        auto dw = lower_bound(haybales.begin(), haybales.end(), a);
        cout << up - dw << '\n';
    }

    return 0;
}
