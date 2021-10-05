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

const int hi = 2e5;

vector<int> graph[hi];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("shuffle");

    int n; cin >> n;

    vector<int> indegree(n+1);

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        graph[i].push_back(a);
        indegree[a]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int u: graph[node]) {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }

    int ans = n;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            ans--;
    }

    cout << ans;

    return 0;
}
