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

const int hi = 2500;

bool fences[hi][hi] = {0};
int x = 1250, y = 1250, ans = 0;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main()
{
    setIO("gates");

    fences[x][y] = 1;
    int n; cin >> n;
    string dir; cin >> dir;

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'N') {
            y += 2;
            if (fences[y][x] && !fences[y-1][x])
                ans++;
            fences[y][x] = 1;
            fences[y-1][x] = 1;
        }
        if (dir[i] == 'S') {
            y -= 2;
            if (fences[y][x] && !fences[y+1][x])
                ans++;
            fences[y][x] = 1;
            fences[y+1][x] = 1;
        }
        if (dir[i] == 'E') {
            x += 2;
            if (fences[y][x] && !fences[y][x-1])
                ans++;
            fences[y][x] = 1;
            fences[y][x-1] = 1;
        }
        if (dir[i] == 'W') {
            x -= 2;
            if (fences[y][x] && !fences[y][x+1])
                ans++;
            fences[y][x] = 1;
            fences[y][x+1] = 1;
        }
    }

    cout << ans;
    return 0;
}
