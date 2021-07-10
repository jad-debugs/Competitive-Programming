#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool graph[1001][1001];
int cows[101];

int main()
{
    // nodes, pastures, edges
    int n, p, e; cin >> n >> p >> e;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        graph[a][a] = 1;
        cows[i] = a;
    }

    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b; 
        graph[a][b] = 1;
    }

    for (int k = 1; k <= p; k++) {
        for (int i = 1; i <= p; i++) {
            if (graph[i][k]) {
                for (int j = 1; j <= p; j++) {
                    graph[i][j] = (graph[i][j]) || (graph[i][k] && graph[k][j]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= p; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[cows[j]][i])
                tmp++;
        }
        if (tmp == n)
            ans++;
    }

    cout << ans;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define f first
// #define s second
// #define pii pair<int, int>

// bool graph[1001][1001];
// int cows[101];
// int cowsReached[1001];
// vector<bool> visited(1001);
// int n, p;

// void dfs(int node)
// {
//     if (visited[node])
//         return;
//     visited[node] = 1;
//     cowsReached[node]++;
//     for (int u = 1; u <= p; u++) {
//         if (graph[node][u]) {
//             dfs(u);
//         }
//     }
// }

// int main()
// {
//     // nodes, pastures, edges
//     int e; cin >> n >> p >> e;

//     for (int i = 0; i < n; i++)
//         cin >> cows[i];

//     for (int i = 0; i < e; i++) {
//         int a, b; cin >> a >> b; 
//         graph[a][b] = 1;
//     }

//     for (int i = 0; i < n; i++) {
//         dfs(cows[i]);
//         fill(visited.begin(), visited.end(), false);
//     }

//     int ans = 0;

//     for (int i = 1; i <= p; i++) {
//         if (cowsReached[i] == n)
//             ans++;
//     }

//     cout << ans;

//     return 0;
// }

