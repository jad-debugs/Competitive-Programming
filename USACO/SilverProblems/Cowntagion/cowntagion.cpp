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

    int n; cin >> n;

    vector<int> g(n);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a-1]++;
    }

    int ans = n-1;

    for (int x: g) {
        if (x == 0)
            continue;
        ans += ceil(log2((double)x));
    }

    cout << ans;

    return 0;
}
