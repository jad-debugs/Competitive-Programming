#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool visited[251][251] = {0};
int ans = 2e9, n, B;
vector<int> snow(251);
// .f is depth, .s is step size
vector<pii> boots(251);

void go(int pos, int b)
{
    if (visited[pos][b])
        return;
    visited[pos][b] = 1;

    if (pos == n-1) {
        ans = min(ans, b);
        return;
    }

    for (int i = pos+1; i < n && i - pos <= boots[b].s; i++) {
        if (boots[b].f >= snow[i])
            go(i, b);
    }

    for (int i = b+1; i < B;i++) {
        if (boots[i].f >= snow[pos])
            go(pos, i);
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

    cin >> n >> B;

    for (int i = 0; i < n; i++)
        cin >> snow[i];
    for (int i = 0; i < B; i++)
        cin >> boots[i].f >> boots[i].s;

    go(0, 0);

    cout << ans << "\n";

    return 0;
}
