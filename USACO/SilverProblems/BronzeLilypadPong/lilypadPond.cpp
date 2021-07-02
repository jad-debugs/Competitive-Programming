#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main() 
{
    int n, m; cin >> n >> m;
    int d1, d2; cin >> d1 >> d2;

    int graph[n][m] = {0};

    pii start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 3)
                start = {i, j};
            if (graph[i][j] == 4)
                end = {i, j};
        }
    }

    return 0;
}
