#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>


int main()
{
    int n, k, p; cin >> n >> k >> p;

    vector<int> sol;
    queue<int> q;

    for (int i = 1; i <= k; i++)
        q.push(i);
    for (int i = 1; i <= k; i++) {
        int card = q.front();
        q.pop();
        if (i%n == 0)
            sol.push_back(card);
        if (q.empty())
            break;
        for (int j = 0; j < p; j++) {
            int cur = q.front();
            q.push(cur);
            q.pop();
        }
    }

    sort(begin(sol), end(sol));

    for (int x: sol)
        cout << x << '\n';

    return 0;
}
