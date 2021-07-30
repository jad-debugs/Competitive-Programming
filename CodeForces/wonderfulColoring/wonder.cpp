#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while (t--) {
        string str;
        cin >> str;

        map<char, int> map;

        for (char a: str) {
            map[a]++;
        }

        int ans = 0;
        int indiv = 0;

        for (auto p: map) {
            if (p.second >= 2)
                ans++;
            else
                indiv++;
        }

        cout << ans + indiv/2 << '\n';
    }
}