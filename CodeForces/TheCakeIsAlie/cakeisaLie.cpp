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

int k;

bool paths(int n, int m, int ans)
{
    if (n == 1 && m == 1)
        return (ans == k);
    if (n > 1)
        return paths(n-1, m, ans + m);
    if (m > 1)
        return paths(n, m-1, ans + n);
    return (ans == k);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main()
{
    setIO("");

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b >> k;
        paths(a, b, 0) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
