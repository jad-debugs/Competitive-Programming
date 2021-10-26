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

    char mat[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }

    set<char> set;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int dot = 0;
            if (mat[i][j] == '.')
                dot++;
            if (mat[i][j+1] == '.')
                dot++;
            if (mat[i+1][j] == '.')
                dot++;
            if (mat[i+1][j+1] == '.')
                dot++;

            if (dot != 2) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}
