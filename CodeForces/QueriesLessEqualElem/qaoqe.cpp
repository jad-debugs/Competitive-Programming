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
    setIO();

    int aS, bS; cin >> aS >> bS;
    vector<int> a(aS);
    vector<int> b(bS);

    for (int i = 0; i < aS; i++)
        cin >> a[i];
    for (int i = 0; i < bS; i++)
        cin >> b[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < bS; i++) {
        cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (i != bS - 1)
            cout << ' ';
    }
    return 0;
}
