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

map<char, int> countDir;

const int mx = 1e9;

int x1, y1, x2, y2, n;

string dir;

bool solve(ll days)
{
    int div = days/n;

    int up = div*countDir['U'];
    int down = div*countDir['D'];
    int left = div*countDir['L'];
    int right = div*countDir['R'];

    for (int i = 0; i < days%n; i++) {
        if (dir[i] == 'U')
            up++;
        else if (dir[i] == 'D')
            down++;
        else if (dir[i] == 'L')
            left++;
        else
            right++;
    }

    int offsetX = x2 - x1;
    int offsetY = y2 - y1;

    if (x2 > x1)
        offsetX += -right + left;
    else
        offsetX += right - left;
    if (y2 > y1)
        offsetY += -up + down;
    else
        offsetY += up - down;

    if (abs(offsetY) + abs(offsetX) <= days)
        return true;
    return false;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    cin >> x1 >> y1 >> x2 >> y2 >> n;

    cin >> dir;

    for (int i = 0; i < n; i++)
        countDir[dir[i]]++;

    ll lo = 0, hi = 1e18;

    if (!solve(1e18)) {
        cout << -1;
        return 0;
    }

    while (lo < hi) {
        ll mid = lo + (hi - lo)/2;

        if (solve(mid))
            hi = mid;
        else
            lo = mid+1;
    }

    cout << hi;

    return 0;
}
