#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

struct Point {
    int x, y1, y2;
    bool isLeft;
};

bool cmp(Point a, Point b)
{
    return a.x < b.x;
}

int main()
{
    int n; cin >> n;

    vector<Point> points;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        // y1 is greater since top left
        points.push_back({x1, y2, y1, 1});
        points.push_back({x2, y2, y1, 0});
    }

    sort(points.begin(), points.end(), cmp);

    int pastX = points[0].x, ans = 0;
    set<pii> yPoints;

    for (int i = 0; i < 2*n; i++) {
        int dx = abs(points[i].x - pastX);
        pastX = points[i].x;

        int top = -2e9, dy = 0, bottom;
        for (pii p: yPoints) {
            if (p.s > top) {
                bottom = max(top, p.f);
                top = p.s;
                dy += abs(top - bottom);
            }
        }

        if (points[i].isLeft)
            yPoints.insert({points[i].y1, points[i].y2});
        else
            yPoints.erase({points[i].y1, points[i].y2});

        ans += dx*dy;
    }

    cout << ans;

    return 0;
}


// cout << "\n----- Here Comes the INFO -----\n";
// cout << "we are comparing " << points[i].x << " and " << pastX << " in the x direction\n";
// cout << "We get the union of these following lengths\n";
// for (pii x: yPoints)
//     cout << "(" << x.f << ", " << x.s << "), ";