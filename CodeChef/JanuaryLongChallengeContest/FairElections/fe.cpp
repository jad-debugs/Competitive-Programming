#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    
    int ans[t];

    for(int i = 0; i < t; i++) {
        int n, m; cin >> n >> m;
        int winner = 0, loser = 0;
        int win[n], lose[m];

        for(int j = 0; j < n; j++) {cin >> win[j]; winner += win[j]; }
        for(int j = 0; j < m; j++) {cin >> lose[j]; loser += lose[j]; }

        if(winner > loser) {
            ans[i] = 0;
            continue;
        }

        sort(win, win+n); sort(lose, lose+m);
        
        int a = -1;

        for(int j = 0; j < min(n, m); j++) {
            winner += lose[m-j-1]; loser -= lose[m-j-1];
            winner -= win[j]; loser += win[j]; 

            if(winner > loser) {
                a = j+1;
                break;
            }
        }
        ans[i] = a;
    }

    for(int i = 0; i < t-1; i++) cout << ans[i] << "\n";
    cout << ans[t-1];
    return 0;
}
