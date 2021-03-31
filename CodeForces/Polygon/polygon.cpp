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

const int mx = 51;

int n;
bool arr[mx][mx];

bool check(int x, int y)
{
    if (y < n-1 && arr[x][y+1])
        return true;
    if (x < n-1 && arr[x+1][y])
        return true;
    return false;
}

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
        cin >> n;

        bool zero = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char tmp; cin >> tmp;
                if (tmp == '0')
                    arr[i][j] = 0;
                else {
                    arr[i][j] = 1;
                    zero = false;
                }
            }
        }

        if (zero) {
            cout << "YES\n";
            continue;
        }

        bool end = true;

        for (int i = 0; i < n; i++) {
            if (arr[i][n-1]) {
                end = false;
                break;
            }
        }
        if (end) {
            for (int i = 0; i < n; i++) {
                if (arr[n-1][i]) {
                    end = false;
                    break;
                }
            }
        }

        if (end) {
            cout << "NO\n";
            continue;
        }

        bool done = false;

        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-1; j++) {
                if (arr[i][j] && !check(i, j)) {
                    cout << "NO\n";
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }

        if (done)
            continue;
        else
            cout << "YES\n";

    }

    return 0;
}
