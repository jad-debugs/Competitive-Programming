// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <iostream>
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

    int forest[1002][1002];
    
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
            if (x == '*')
                forest[i+1][j+1]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            forest[i][j] += forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << forest[x2][y2] - forest[x1-1][y2] - forest[x2][y1-1] + forest[x1-1][y1-1] << "\n";
    }

    return 0;
}
