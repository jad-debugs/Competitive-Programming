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

const int hi = 1e4;

int n;

vector<int> x(hi);
vector<int> y(hi);
vector<bool> visited(hi);
bool graph[hi][hi] = {0};

int dfs (int v)
{
    int cows = 0;

    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (visited[i] || !graph[v][i])
            continue;
        cows += dfs(i);
    }

    return cows+1;
}

bool works (ll mid)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll distance = (x[j] - x[i])*(x[j] - x[i])+(y[j] - y[i])*(y[j] - y[i]);
            if (distance <= mid) {
                graph[i][j] = 1;
            }
        }
    }

    fill(visited.begin(), visited.end(), 0);
    int cows = dfs(0);
    return cows == n;
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
    setIO("moocast");

    cin >> n;


    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    ll l = 0, r = 1e10; // > 25k^2

    while (l < r) {
        ll mid = l + (r-l)/2;
        if (works(mid)) {
            r = mid;
        }
        else
            l = mid+1;
    }

    cout << l;

    return 0;
}
