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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int graph[1005][1005] = {0};

int main()
{
    setIO("paintbarn");

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        graph[x1][y1]++;
        graph[x1][y2]--;
        graph[x2][y1]--;
        graph[x2][y2]++;
    }
    
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            graph[i][j] += graph[i-1][j] + graph[i][j-1] - graph[i-1][j-1];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (graph[i][j] == k)
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
