#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;

int main()
{
    int n; cin >> n;
    
    vector<pair<pii, int>> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i].f.f >> times[i].f.s;
        times[i].s = i;
    }
    sort(times.begin(), times.end());
    
    vector<int> ans(n);
    priority_queue<pair<int, int>> pq;
    int room = 0, ansI = 0;

    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            room++;
            ans[times[i].s] = room;
            pq.push({-times[i].f.s, room});
        }
        else if (-times[i].f.f < pq.top().f) {
            ans[times[i].s] = pq.top().s;
            pq.push({-times[i].f.s, pq.top().s});
            pq.pop();
        }
        else {
            room++;
            ans[times[i].s] = room;
            pq.push({-times[i].f.s, room});
        }
        ansI = max(ansI, room);
    }
    cout << ansI << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i+1 < n)
            cout << ' ';
    }
    return 0;
}
