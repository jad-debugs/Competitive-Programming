// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}

const int hi = 2e5;
int n, m, cnt = 0;

vector<int> graph[hi];
vector<pair<int, int>> coor;
bool visited[hi] = {false};

struct cow {
    int x1, y1, x2, y2;
};

map<int, cow> ans;

void dfs(int node) {
    if(visited[node]) return;

    int minX = min(ans[cnt].x1, coor[node].first);
    int maxX = max(ans[cnt].x2, coor[node].first);
    int minY = min(ans[cnt].y1, coor[node].second);
    int maxY = max(ans[cnt].y2, coor[node].second);
    ans[cnt] = {minX, minY, maxX, maxY};

    visited[node] = true;
    for(auto u: graph[node]) {
        dfs(u);
    }
}

void cc() {
    for(int v = 0; v < n+1; v++) {
        if(!visited[v]) {
            cnt++;
            ans[cnt] = {hi, hi, 0, 0};
            dfs(v);
        }
    }
    return;
}

int main()
{
    setIO("fenceplan");

    cin >> n >> m;

    coor.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        coor.push_back({a, b});
    }
    

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cc();

    int res = hi;
    
    for(pair<int, cow> m: ans) {
        if(m.second.x1 == 0 && m.second.x1 == m.second.x2 && m.second.x2 == m.second.y1 && m.second.y1 == m.second.y2)
            continue;
        res = min(res, 2*(abs(m.second.x2-m.second.x1)+abs(m.second.y2-m.second.y1)));
    }

    cout << res;

    return 0;
}
