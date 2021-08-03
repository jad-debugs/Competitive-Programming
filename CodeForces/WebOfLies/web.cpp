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

const int mx = 3e5;

vector<set<int>> graph(mx);
set<int> direct;
map<int, int> dd;

int main()
{

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        // direct.insert(min(a, b), max(a, b));
        direct.insert(min(a, b));
        dd[min(a, b)]++;
    }

    int q; cin >> q;
    while (q--) {
        int r; cin >> r;
        if (r == 1) {
            int a, b; cin >> a >> b;
            graph[a].insert(b);
            graph[b].insert(a);
            // direct.insert(min(a, b), max(a, b));
            direct.insert(min(a, b));
            dd[min(a, b)]++;
        }
        if (r == 2) {
            int a, b; cin >> a >> b;
            graph[a].erase(b);
            graph[b].erase(a);

            // pii p = {min(a, b), max(a, b)};
            // if (direct.find(p) != direct.end())
                // direct.erase(p);
            int mn = min(a, b);
            dd[mn]--;
            if (dd[mn] == 0) {
                if (direct.find(mn) != direct.end()) {
                    direct.erase(mn);
                }
            }
            
        }
        if (r == 3) {
            cout << n - direct.size() << '\n';
        }
    }

    return 0;
}
