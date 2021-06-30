#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main()
{
    int n; cin >> n;

    vector<pair<string, pair<bool, string>>> names;
    vector<string> org(n);
    map<string, pair<int, int>> pos;

    for (int i = 0; i < n; i++) {
        string str; cin >> str; 

        sort(str.begin(), str.end());
        org[i] = str;
        names.push_back({str, {0, str}});

        string sorted = str;

        reverse(str.begin(), str.end());
        names.push_back({str, {1, sorted}});
    }

    sort(names.begin(), names.end());

    int A = 0, RA = 0;

    for (auto pair: names) {
        if (pair.s.f == 1) {
            RA++;
            pos[pair.s.s].s = A;
        }
        else {
            A++;
            pos[pair.s.s].f = RA+1;
        }
    }

    for (string str: org) {
        cout << pos[str].f << ' ' << pos[str].s << '\n';
    }
}