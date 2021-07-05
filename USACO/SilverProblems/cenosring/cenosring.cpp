#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    string s, t; cin >> s >> t;

    const int ssz = s.size();
    const int tsz = t.size();

    string a = "";
    for (int i = 0; i < ssz; i++) {
        a += s[i];
        if ((int)a.size() >= tsz && a.substr((int)a.size() - tsz, tsz) == t)
            a.resize((int)a.size() - tsz);
    }

    cout << a;

    return 0;
}
