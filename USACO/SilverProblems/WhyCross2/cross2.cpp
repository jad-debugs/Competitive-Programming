#include <bits/stdc++.h>
using namespace std;

const int LEN = 1e5;

int main()
{
    int n; cin >> n;

    int fj[3][LEN] = {0};

    // H P S = 0 1 2

    for (int i = 1; i <= n; i++) {
        char a; cin >> a;

        if (a == 'H') {
            fj[0][i] = fj[0][i-1]+1;
            fj[1][i] = fj[1][i-1];
            fj[2][i] = fj[2][i-1];
        }
        else if (a == 'P') {
            fj[1][i] = fj[1][i-1]+1;
            fj[2][i] = fj[2][i-1];
            fj[0][i] = fj[0][i-1];
        }
        else {
            fj[2][i] = fj[2][i-1]+1;
            fj[1][i] = fj[1][i-1];
            fj[0][i] = fj[0][i-1];
        }
    }

    int ans = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) // must switch turns
                continue;
            for (int a = 1; a <= n; a++) {
                ans = max(ans, fj[i][a] + fj[j][n] - fj[j][a]); // pf of front + (pf of all - pf of front)
            }
        }
    }

    cout << ans;

    return 0;
}
