#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n, m;
    cin >> n >> m;

    // sorts by time passed as pf sum but velocity there is .s
    set<pii> bess;
    set<pii> elsie;
    set<int> points;

    int pfTime = 0;
    for (int i = 0; i < n; i++) {
        int v, t; cin >> v >> t;
        pfTime += t;
        bess.insert({pfTime, v});
        points.insert(pfTime);
    }

    pfTime = 0; 
    for (int i = 0; i < m; i++) {
        int v, t; cin >> v >> t;
        pfTime += t;
        elsie.insert({pfTime, v});
        points.insert(pfTime);
    }

    int bessDistance = 0, elsieDistance = 0, ans = 0, bessWin = -1, prevTime = 0;


    for (int x: points) {
        int timeRan = x - prevTime;

        int speedB = bess.lower_bound({x, 0})->s;
        int speedE = elsie.lower_bound({x, 0})->s;

        bessDistance += timeRan*speedB;
        elsieDistance += timeRan*speedE;

        prevTime = x;
        cout << endl;

        if (bessDistance > elsieDistance) {
            if (bessWin == -1) {
                bessWin = 1;
                continue;
            }
            else if (bessWin == 0) {
                ans++;
                bessWin = 1;
            }
        }

        else if (elsieDistance > bessDistance) {
            if (bessWin == -1) {
                bessWin = 0;
                continue;
            }
            else if (bessWin == 1) {
                ans++; 
                bessWin = 0;
            }
        }
    }

    cout << ans;

    return 0;
}
