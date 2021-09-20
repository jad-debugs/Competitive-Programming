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

const int mx = 2e5;
int n, m, k, nodes = 1;

vector<int> graph[mx];
set<pii> tmp2[mx];
vector<int> tmp[mx];
int outdegree[mx];

void countNodes(int s, int e)
{
    outdegree[s] = 1;
    for (int u: tmp[s]) {
        if (u == e)
            continue;
        countNodes(u, s);
        outdegree[s] += outdegree[u];
    }
}

void makeGraph(int node)
{
    for (int u: tmp[node]) {
        tmp2[node].insert({-outdegree[u], u});
        makeGraph(u);
    }
}

void makeGraph2(int node)
{
    int i = 0;
    for (pii u: tmp2[node]) {
        if (i >= k)
            break;
        graph[node].push_back(u.s);
        i++;
        makeGraph2(u.s);
    }
}

void dfs(int node)
{
    for (int u: graph[node]) {
        dfs(u);
        nodes++;
    }
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
    setIO("evacuation");

    cin >> n >> m >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        tmp[a].push_back(b);
    }

    countNodes(1, 0);

    makeGraph(1);
    makeGraph2(1);
    dfs(1);

    cout << ceil(m/1.0/nodes);

    return 0;
}

/*
void dfs(int node, int mn, int ppl)
{
    if (!works)
        return;

    if (ppl <= mn)
        return;
    ppl -= mn;

    for (int u: graph[node]) {
        int newG = (ceil(ppl/1.0/(min(outdegree[node], k))));
        ppl -= newG;
        dfs(u, mn, newG);
    }
    if (graph[node].size() == 0 && ppl > mn) {
        works = false;
        return;
    }
}
*/