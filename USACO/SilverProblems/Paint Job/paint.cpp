#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;

    int n, p; cin >> n >> p;

    vector<int> sol(p, -1);

    vector<int> colors(n);
    for (int i = 0; i < n; i++)
        cin >> colors[i];

    sol[a] = 0;

    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == b)
            break;

        for (int i = 0; i < n; i++) {
            int newC = (colors[i]*cur)%p;
            if ((sol[cur]+1 < sol[newC] && newC > 0) || sol[newC] == -1) {
                q.push(newC);
                sol[newC] = sol[cur]+1;
            }
        }
    }

    cout << sol[b];

    return 0;
}
