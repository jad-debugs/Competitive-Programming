#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int hi = 201;
const int mx = 2e9;
int matrix[hi][hi] = {0};

int n;

int col(int r, int c)
{
    int res = -mx, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[(r+i)%n][c];
        res = max(res, sum);
    }

    return res;
}

int row(int r, int c)
{
    int res = -mx, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[r][(c+i)%n];
        res = max(res, sum);
    }

    return res;
}
int diag1(int r, int c)
{
    int res = -mx, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[(r+i)%n][(c+i)%n];
        res = max(res, sum);
    }

    return res;
}
int diag2(int r, int c)
{
    int res = -mx, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[(r+i)%n][(c-i+n)%n];
        res = max(res, sum);
    }

    return res;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int ans = -mx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, row(i, j));
            ans = max(ans, col(i, j));
            ans = max(ans, diag1(i, j));
            ans = max(ans, diag2(i, j));
        }
    }

    cout << ans << '\n';

    return 0;
}
