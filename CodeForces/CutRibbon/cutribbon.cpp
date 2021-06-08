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

    int a, b, c, ans = 0; cin >> a >> b >> c;

    for (int i = 0; i <= 4000; i++) {
        for (int j = 0; j <= 4000; j++) {
            int z = n - a*i - b*j;
            if (z%c != 0 || z < 0)
                continue;
            else
                z /= c;
            ans = max(ans, i+j+z);
        }
    }

    cout << ans;

    return 0;
}
