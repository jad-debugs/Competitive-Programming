#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pii pair<int, int>

struct point
{
    int x, id;
    bool isLeft;
};

bool cmp(point a, point b)
{
    if (a.x == b.x)
        return (a.isLeft != b.isLeft);
    return a.x < b.x;
}

int main()
{
    int n; cin >> n;

    vector<point> points;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        points.push_back({a, i, 1});
        points.push_back({b, i, 0});
    }

    sort(begin(points), end(points), cmp);

    int alone[n] = {0}, total = 0, endpoint = points[0].x;
    set<int> s;

    for (point p: points) {
        if ((int)s.size() == 1)
            alone[*s.begin()] += p.x - endpoint;
        if (!s.empty())
            total += p.x - endpoint;
        if (p.isLeft)
            s.insert(p.id);
        else
            s.erase(p.id);
        endpoint = p.x;
    }

    int tmpT = total;

    for (int i = 0; i < n; i++) {
        total = min(total, tmpT - alone[i]);
    }

    cout << total;

    return 0;
}
