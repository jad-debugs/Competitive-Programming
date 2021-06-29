#include <bits/stdc++.h>
using namespace std;

int n, m;
int spot[501][51], no_spot[501][51], b64[64];

bool spotted(int a, int b, int c)
{
    bool ret = true;
    for (int i = 0; i < n; i++) {
        b64[spot[i][a]*16 + spot[i][b]*4 + spot[i][c]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (b64[no_spot[i][a]*16 + no_spot[i][b]*4 + no_spot[i][c]])
            ret = false;
    }
    for (int &x: b64)
        x = 0;
    return ret;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string genome; cin >> genome;
        for (int j = 0; j < m; j++) {
            if (genome[j] == 'A')
                spot[i][j] = 0;
            else if (genome[j] == 'C')
                spot[i][j] = 1;
            else if (genome[j] == 'G')
                spot[i][j] = 2;
            else
                spot[i][j] = 3;
        }
    }

    for (int i = 0; i < n; i++) {
        string genome; cin >> genome;
        for (int j = 0; j < m; j++) {
            if (genome[j] == 'A')
                no_spot[i][j] = 0;
            else if (genome[j] == 'C')
                no_spot[i][j] = 1;
            else if (genome[j] == 'G')
                no_spot[i][j] = 2;
            else
                no_spot[i][j] = 3;
        }
    }

    int ans = 0;

    for (int a = 0; a < m; a++) {
        for (int b = a+1; b < m; b++) {
            for (int c = b+1; c < m; c++) {
                ans += (spotted(a, b, c) ? 1: 0);
            }
        }
    }

    cout << ans;

    return 0;
}
