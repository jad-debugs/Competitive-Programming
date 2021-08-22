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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char graph[21][21];
int visited[21][21];

bool flag = false;

set<pair<pii, pii>> ult;

void ff(int r, int c, int mnX, int mnY, int mxX, int mxY, int color, char prev)
{
    if (r < mnX || r > mxX || c < mnY || c > mxY || visited[r][c] == color || (prev != 'x' && prev != graph[r][c]))
        return;
    visited[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        ff(r2, c2, mnX, mnY, mxX, mxY, color, graph[r][c]);
    }
}

bool check(int mnX, int mnY, int mxX, int mxY, int color)
{
    map<char, int> map; 
    set<char> charactersFound;

    for (int i = mnX; i <= mxX; i++) {
        for (int j = mnY; j <= mxY; j++) {
            if (visited[i][j] != color) {
                ff(i, j, mnX, mnY, mxX, mxY, color, graph[i][j]);
                map[graph[i][j]]++;
            }
            charactersFound.insert(graph[i][j]);
        }
    }
    bool ok1 = false, ok2 = false;
    for (auto x: map) {
        if (x.s == 1)
            ok1 = true;
        if (x.s >= 2)
            ok2 = true;
    }
    if (ok1 && ok2 && (int)charactersFound.size() == 2)
        return true;
    return false;
}

// checks if b is inside a
bool inside(pair<pii, pii> a, pair<pii, pii> b)
{
    return (b.f.f >= a.f.f && b.f.s >= a.f.s && b.s.f <= a.s.f && b.s.s <= a.s.s);
}

bool works(pair<pii, pii> a)
{
    for (auto u: ult) {
        if (a != u && inside(u, a))
            return false;
    }
    return true;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {
    setIO("where");

    int n; cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }


    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = i; a < n; a++) {
                for (int b = j; b < n; b++) {
                    if (check(i, j, a, b, ++c)) {
                        ult.insert({{i, j}, {a, b}});
                    }
                }
            }
        }
    }

    int ans = 0;

    for (auto i: ult) {
        // if we are not inside another pcl, we are a pcl at this point
        if (works(i)) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}