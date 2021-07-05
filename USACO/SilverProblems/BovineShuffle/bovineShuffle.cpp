#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;
    vector<int> graph[n];
    vector<int> indegree(n);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a--;
        // 0 index DONT FORGET
        graph[i].push_back(a);
        indegree[a]++;
    }

    queue<int> q;
    int ans = n;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            ans--;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                ans--;
                q.push(v);
            }
        }
    }

    cout << ans;

    return 0;
}
