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

const int MX = 3e5;

int n;

vector<int> tree[MX];
int subtree[MX] = {0};

void dfs(int cur)
{
    subtree[cur] = 1;
    for (int u: tree[cur]) {
        dfs(u);
        subtree[cur] += subtree[u];
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
    setIO("");

    cin >> n;

    for (int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        tree[a].push_back(i);
    }

    dfs(0);

    for (int i = 0; i < n-1; i++) {
        cout << subtree[i]-1 << ' ';
    }
    cout << subtree[n-1]-1;
    return 0;
}
