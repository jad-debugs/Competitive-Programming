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

void LeftRight(int r, int c, vector<vector<bool>> graph, int i, int j, int dist, int &ans)
{
    bool leftW = true, rightW = true;

    // going left first
    if (j - dist >= 0) {
        for (int a = j; a >= j - dist; a--) {
            if (!graph[i][a])
                leftW = false;
        }
    }
    if (leftW)
        ans++;
    if (j + dist < c) {
        for (int a = j; a <= j + dist; a++) {
            if (!graph[i][a])
                rightW = false;
        }
    }
    if (rightW)
        ans++;
}

void UpDown(int r, int c, vector<vector<bool>> graph, int i, int j, int ans)
{
    // going up first
    int tmpi = i;
    while (tmpi < r && graph[tmpi][j])
        tmpi++;
    tmpi--;
    LeftRight(r, c, vector<vector<bool>> graph, int i, j, 2*(i - tmpi+1), ans)
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

    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";
        
        int r, c; cin >> r >> c;
        vector<vector<bool>> graph(r, vector<bool>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool a; cin >> a;
                graph[i][j] = a;
            }
        }

        int ans = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (graph[i][j] == 1) {

                }
            }
        }
    }

    return 0;
}
