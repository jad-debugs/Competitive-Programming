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

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool grid[3000][3000];

pii check(int a, int b) {
    int cnt = 0;
    pii ans;
    if (!grid[a][b])
        return {0, 0};

    for (int i = 1; i < 5; i++) {
        int r = a + dx[i];
        int c = b + dy[i];
        if (grid[r][c]) {
            cnt++;
        }
        if (!grid[r][c])
            ans = {r, c};
    }
    if (cnt != 3)
        return {0, 0};
    else
        return ans;
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

    int t; cin >> t;
    int ans = 0;
    queue<pii> q;

    for (int z = 1; z <= t; z++) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;

        q.push({x, y});

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (grid[a][b])
                continue;

            ans++;
            grid[a][b] = 1;

            for (int i = 0; i < 5; i++) {
                int r = a + dx[i];
                int c = b + dy[i];
                pii tmp = check(r, c);
                if (tmp.f != 0 && tmp.s != 0) {
                    q.push({tmp.f, tmp.s});
                }
            }
        }
        cout << ans - z << "\n";
    }

    return 0;
}
