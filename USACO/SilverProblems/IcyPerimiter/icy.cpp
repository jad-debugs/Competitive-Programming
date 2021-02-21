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

char graph[1001][1001];
bool visited[1001][1001];

pii stats = {0, 0};

int n;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}

void ff(int c, int r)
{
    if(c < 0 || c >= n || r < 0 || r >= n || visited[c][r] || graph[c][r] != '#')
        return;
    visited[c][r] = true;
    stats.f++;
    
    if((c-1 >= 0 && graph[c-1][r] != '#') || c-1 < 0)
        stats.s++;
    if((c+1 < n && graph[c+1][r] != '#') || c+1 >= n)
        stats.s++;
    if((r+1 < n && graph[c][r+1] != '#') || r+1 >= n)
        stats.s++;
    if((r-1 >= 0 && graph[c][r-1] != '#') || r-1 < 0)
        stats.s++;
    
    ff(c-1, r);
    ff(c+1, r);
    ff(c, r-1);
    ff(c, r+1);
}

int main()
{
    setIO("perimeter");

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
    vector<pii> ap;

    ff(0, 0);
    ap.push_back(stats);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            stats.f = 0;
            stats.s = 0;
            if(!visited[i][j] && graph[i][j] == '#') {
                ff(i, j);
                ap.push_back(stats);
            }
            
        }
    }

    int areaAns = 0;
    int permAns = 0;
    for(pii x: ap) {
        if(x.f > areaAns) {
            areaAns = x.f;
            permAns = x.s;
        }
        else if(x.f == areaAns) {
            if(x.s < permAns)
                permAns = x.s;
        }
    }
    cout << areaAns << " " << permAns;
    return 0;
}
