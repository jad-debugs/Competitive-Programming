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
        string alpha; cin >> alpha;
        const int len = alpha.size();

        int aPos = 0;
        bool found = 0;

        for (int i = 0; i < len; i++) {
            if (alpha[i] == 'a') {
                aPos = i;
                found = 1;
            }
        }
        if (!found) {
            cout << "NO\n";
            continue;
        }

        char cur = 'b';
        bool works = true;
        for (int i = aPos-1, j = aPos+1; (i >= 0 || j < len) && cur <= 'z'; ) {
            if (j < len && alpha[j] == cur)
                j++;
            else if (i >= 0 && alpha[i] == cur)
                i--;
            else {
                works = false;
                break;
            }
            cur++;
        }
        if (works)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
