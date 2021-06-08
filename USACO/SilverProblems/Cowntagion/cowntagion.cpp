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

const int hi = 1e5+5;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main()
{
    setIO("");

    int n; cin >> n;

    vector<int> g(hi);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--;
        g[a]++;
    }

    int ans = n-1;

    for (int i = 0; i < n; i++) {
        int x = g[i];

        int tmp = 0, p = 1;
        while (p < x+1)
            tmp++, p *= 2;
        
        ans += tmp;
    }

    cout << ans;

    return 0;
}
