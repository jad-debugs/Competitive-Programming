#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool matrix[100][100] = {0};

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        matrix[a][b] = 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ((matrix[i][j]) || (matrix[i][k] && matrix[k][j]));
            }
        }
    }

    vector<int> rows(n);
    vector<int> cols(n);

    for (int i = 0; i < n; i++) {
        int r = 0, c = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j])
                r++;
            if (matrix[j][i])
                c++;
        }
        rows[i] = r;
        cols[i] = c;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (rows[i] + cols[i] == n-1)
            ans++;
    }

    cout << ans;

    return 0;
}
