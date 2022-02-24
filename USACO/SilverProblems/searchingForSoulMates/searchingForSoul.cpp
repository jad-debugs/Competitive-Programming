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

ll multM(ll a, ll b)
{
    ll ans = 0;

    while (a != b) {
        ll start = a;

        int k = 0;
        while (true) {
            if (start*2 > b)
                break;
            else {
                start *= 2;
                k++;
            }
        }

        ll newNum = b/(1 << k);
        ans += newNum - a;
        a = newNum*(1 << k);

        if (a != b) {
            a = newNum*2;
            ans++;
        }
        else {
            ans += k;
        }
    }
    return ans;
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
    // setIO("");

    int t; cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        ll cur = a;
        ll tmpAns = 0;

        ll bestAns;
        if (a <= b)
            bestAns = multM(a, b);
        else
            bestAns = 1e18;

        while (cur >= 2) {
            if (cur <= b) {
                bestAns = min(bestAns, tmpAns + multM(cur, b));
            }
            if (cur%2==1)
                cur++;
            else
                cur /= 2;

            tmpAns++;
        }

        cout << bestAns << "\n";
    }

    return 0;
}
