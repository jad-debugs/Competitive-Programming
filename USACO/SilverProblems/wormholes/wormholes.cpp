#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

vector<int> x;
vector<int> y;
vector<int> edge(13);
vector<int> rightP(13);
bool visited[13][13];
int n, ans = 0;

int cycle()
{
    for (int i = 1; i <= n; i++) {
        int past = i;
        for (int j = 1; j <= n; j++) {
            past = rightP[edge[past]];
        }
        // if we get the worm hole to our right is non existent (0),
        // there cant be a cycle (after we try n worm holes)
        if (past != 0)
            return 1;
    }
    return 0;
}

void go(int pairs)
{
    // attempt to try unpaired worm holes first, instead of all at once
    int wormhole = -1;
    for (int i = 1; i <= n; i++) {
        if (!edge[i]) {
            wormhole = i;
            break;
        }
    }
        
    if (wormhole == -1) {
        ans += cycle();
        return;
    }

    for (int i = wormhole+1; i <= n; i++) {
        if (edge[i] != 0)
            continue;
        edge[wormhole] = i;
        edge[i] = wormhole;
        // cout << i << ' ' << j << '\n';
        go(pairs+1);
        edge[wormhole] = 0;
        edge[i] = 0;
    }
}

int main()
{
    cin >> n;  

    x.resize(n+1);
    y.resize(n+1);

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[j] > x[i] && y[i] == y[j]) {
                if (rightP[i] == 0 || x[j] - x[i] < x[rightP[i]] - x[i])
                    rightP[i] = j;
            }
        }
    }

    go(0);

    cout << ans;

    return 0;
}
