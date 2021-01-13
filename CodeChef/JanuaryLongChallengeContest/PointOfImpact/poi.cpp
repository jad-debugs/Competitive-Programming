#include <bits/stdc++.h>
using namespace std;

struct C {
    int x, y;
};

int main()
{
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k; cin >> n >> k;
        C p; cin >> p.x >> p.y;
        
        C tmp[4];
        
        if(p.x == p.y) {
            cout << n << " " << n << "\n";
            continue;
        }

        if(p.x > p.y) {
            tmp[0] = {n, p.y + n - p.x};
            tmp[1] = {p.y + n - p.x, n};
            tmp[2] = {0, p.x - p.y};
            tmp[3] = {p.x - p.y , 0};
        }

        else {
            tmp[0] = {p.x + n - p.y, n};
            tmp[1] = {n, p.x + n - p.y};
            tmp[2] = {p.y - p.x, 0};
            tmp[3] = {0, p.y - p.x};
        }
        C ans = tmp[(k-1)%4];
        cout << ans.x << " " << ans.y << "\n";
    }

    return 0;
}
