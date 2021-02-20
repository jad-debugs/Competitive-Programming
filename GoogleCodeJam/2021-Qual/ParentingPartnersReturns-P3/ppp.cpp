// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
typedef pair<int, int> pii;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

bool cmp(pii a, pii b) {
    if(a.s == b.s)
        return a.f < b.f;
    return a.s < b.s;
}

int main()
{
    setIO();

    int t; cin >> t;

    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int n; cin >> n;
        pii org[n];
        for(int a = 0; a < n; a++) {
            int c, d; 
            cin >> c >> d;
            org[a] = {c, d};
        }
        pii so[n];
        copy(org, org+n, so);

        sort(so, so+n, cmp);

        pii j = {0, 0};
        pii c {0, 0};

        char ans[n];

        int cur = 0;
        int o = 0;

        char curC = 'J';

        int cnt = 0;
        bool imp = false;

        for(int i = 0; i < n; i++) {
            pii x = so[i];
            if(x.f >= cur) {
                cur = x.s;
            }
            else if (x.f >= o) {
                o = cur;
                cur = x.s;
                if(curC == 'J') curC = 'C';
                else curC = 'J';
            }
            else {imp = true; break;}
            ans[cnt] = curC;
            cnt++;
        }
        if(imp) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for(auto p: org) {
            for(int i = 0; i < n; i++) {
                if(so[i].f == p.f && so[i].s == p.s)
                    cout << ans[i];
            }
        }
        cout << "\n";
    }

    return 0;
}
