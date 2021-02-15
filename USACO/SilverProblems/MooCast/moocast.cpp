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

vector<int> graph[201];
bool visited[201] = {false};
int cnt = 0;

void dfs(int node) {
    if(visited[node])
        return;
    visited[node] = true;
    cnt++;

    for(int u: graph[node]) {
        dfs(u);
    }
}

struct inp {
    int x, y, w;
};


int main()
{
    setIO("moocast");

    int n; cin >> n;

    inp arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].w;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int xr = abs(arr[i].x - arr[j].x);
            int yr = abs(arr[i].y - arr[j].y);
            if(xr*xr + yr*yr <= arr[i].w * arr[i].w) {
                graph[i].push_back(j);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        dfs(i);
        ans = max(ans, cnt);
        cnt = 0;
        for(int i = 0; i < n; i++)
            visited[i] = false;
    }

    cout << ans;

    return 0;
}
