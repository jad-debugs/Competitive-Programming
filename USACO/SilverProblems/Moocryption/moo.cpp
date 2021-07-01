#include <bits/stdc++.h>
using namespace std;

char letters[55][55] = {0};
int n, m;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

char check(int a, int b)
{
    if (a < 0 || a >= n || b < 0 || b >= m)
        return '*';
    return letters[a][b];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> letters[i][j];
        }
    }

    int ans = 0;

    for (char a = 'A'; a <= 'Z'; a++) {
        if (a == 'M')
            continue;
        for (int b = 'A'; b <= 'Z'; b++) {
            if (b == a || b == 'O')
                continue;
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (check(i, j) != a)
                        continue;
                    for (int c = 0; c < 8; c++) {
                        if ((check(i + dx[c], j + dy[c]) == b) && 
                            (check(i + 2*dx[c], j + 2*dy[c]) == b))
                            tmp++;
                    }
                }
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans;

    return 0;
}
