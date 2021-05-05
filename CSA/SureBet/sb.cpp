#include <bits/stdc++.h>
using namespace std;

bool cmp(double a, double b)
{
    return a > b;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    // cin.tie(nullptr);

    int n; cin >> n;
    vector<double> a(n);
    vector<double> b(n);

    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        a[i] = x-1;
        b[i] = y-1;
    }

    sort(begin(a), end(a), cmp);
    sort(begin(b), end(b), cmp);

    double Aans = 0, Bans = 0;
    double ans = 0.0;

    for (int l = 0, r = 0; l < n; l++) {
        Aans += a[l];
        Bans--;
        ans = fmax(ans, min(Aans, Bans));
        while (r < n && Bans < Aans) {
            Aans--;
            Bans += b[r];
            r++;
            ans = fmax(ans, min(Aans, Bans));
        }
        ans = fmax(ans, min(Aans, Bans));
    }
    printf("%.4lf",(double)ans);
}
