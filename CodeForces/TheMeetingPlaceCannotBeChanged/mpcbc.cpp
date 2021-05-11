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

int n;
bool solve(vector<int> pos, vector<int> speeds, long double d)
{
    long double maxl = -2e9, minr = 2e9;
    for (int i = 0; i < n; i++) {
        maxl = max(maxl, pos[i] - d*speeds[i]);
        minr = min(minr, pos[i] + d*speeds[i]);
    }
    return maxl <= minr;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    cin >> n;

    vector<int> pos(n);
    vector<int> speeds(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }

    long double lo = 0, hi = 1e9;
    const long double alt = 1e-9;
    while (lo + alt < hi) {
        long double mid = lo + (hi - lo)/2;
        if (solve(pos, speeds, mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << setprecision(18) << lo << '\n';
    return 0;
}
