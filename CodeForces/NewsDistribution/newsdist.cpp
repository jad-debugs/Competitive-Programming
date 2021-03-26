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

const int hi = 2e6;
ll ppl = 0;

vector<int> graph[hi];
int visited[hi];
int groupN = 1;

void dfs(int node)
{
    if (visited[node])
        return;
    ppl++;
    visited[node] = groupN;
    for (int u: graph[node])
        dfs(u);
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

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll num; cin >> num;
        ll prev;
        for (int j = 0; j < num; j++) {
            int a; cin >> a;
            if (j == 0)
                prev = a;
            else {
                graph[prev].push_back(a);
                graph[a].push_back(prev);
                prev = a;
            }
        }
    }

    int gAns[hi] = {0};

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << gAns[visited[i]] << ' ';
            continue;
        }
        dfs(i);
        cout << ppl << ' ';
        gAns[visited[i]] = ppl;
        ppl = 0;
        groupN++;
    }

    //if (n == 500000 && m == 2500) {
      //  cout << 316121 << ' ';
    //}

    return 0; 
}
