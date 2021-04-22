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
}


int main()
{
    setIO("");

    int n, m; cin >> n >> m;

    vector<int> city(n);
    vector<int> cell(m);

    for (int i = 0; i < n; i++)
        cin >> city[i];
    for (int i = 0; i < m; i++)
        cin >> cell[i];

    int l = 0, r = 0, ans = 0;
    for (int x: city) {
        while (r+1 < m && cell[r] < x)
            r++;
        if (r != 0)
            l = r - 1;
        ans = max(ans, min(abs(cell[r] - x), abs(cell[l] - x)));
    }
    cout << ans;
    return 0;
}
