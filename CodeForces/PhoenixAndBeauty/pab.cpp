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
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int t; cin >> t;

    while (t--) {
        int n, sub; cin >> n >> sub;

        unordered_set<int> us;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            us.insert(a);
        }

        // cant repeat if < sub
        if ((int)us.size() > sub) {
            cout << "-1\n";
        }

        else {
            cout << n*sub << "\n";

            // I think this can just go to max num of times a single num appears
            // but there is no point in risking it since N*B works based
            // on the constraints given
            for (int i = 0; i < n; i++) {
                for (auto x: us)
                    cout << x << ' ';
                // comfort each sub with 1s to repeat sub
                for (int j = 0; j < sub - (int)us.size(); j++)
                    cout << "1 ";
            }
            cout << "\n";
        }
    }

    return 0;
}
