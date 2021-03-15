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
    setIO("");

    int t; cin >> t;

    while (t--) {
        ll a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f; // n e c po pm pk

        vector<ll> sol;
        vector<ll> front;

        for (int i = 0; i <= a+1; i++)
            front.push_back(i);

        for (ll i = 0; i <= a; i++) {
            ll idx1 = lower_bound(front.begin(), front.end(), (2*a-b-2*i)) - front.begin();
            ll idx2 = upper_bound(front.begin(), front.end(), (c-3*i)) - front.begin() - 1;

            if (idx2 < idx1 || idx1 == a+1)
                continue;
            if (idx2 == a+1 && idx2 + 3 * i > c)
                continue;
            ll det;
            if (f > d)
                det = (idx1 < (a-i) ? idx1 : (a - i));
            else
                det = (idx2 < (a - i) ? idx2 : (a-i));

            ll det2 = a - det - i;
            if (det+i*2 >= 2*a-b && det+3*i <= c)
                sol.push_back(d*det2+e*i+f*det);
        }
            if (!sol.size())
                cout << "-1" << "\n";
            else {
                ll mn = sol[0];
                for (ll j = 0; j < sol.size(); j++)
                    mn = min(mn, sol[j]);

                cout << mn << "\n";
            }
    }
    return 0;
}
