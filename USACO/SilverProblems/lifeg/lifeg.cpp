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
        return a.isLeft;
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

    sort(begin(points), end(points));

    int alone[n] = {0}, total = 0, endpoint = 0;
    set<int> s;

    for (point p: points) {
        if ((int)s.size() == 1)
            alone[*s.begin()] += p.x - endpoint;
        if ((int)s.size())
            total += p.x - endpoint;
        if (p.isLeft)
            s.insert(p.id);
        else
            s.erase(p.id);
    }

    return 0;
}
