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
        int n; cin >> n;
        string enemy, team; cin >> enemy >> team;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (enemy[i] == '0' && team[i] == '1') {
                enemy[i] = 'X';
                team[i] = '0';
                ans++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (team[i] == '0')
                continue;

            if (i - 1 >= 0) {
                if (enemy[i-1] == '1') {
                    enemy[i-1] = '0';
                    ans++;
                    continue;
                }
            }


            if (i + 1 < n) {
                if (enemy[i+1] == '1') {
                    enemy[i+1] = '0';
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
