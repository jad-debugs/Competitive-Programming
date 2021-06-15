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
    ll div = days/n;

    ll up = div*countDir['U'];
    ll down = div*countDir['D'];
    ll left = div*countDir['L'];
    ll right = div*countDir['R'];

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

    ll offsetX = right - left + x1;
    ll offsetY = up - down + y1;


    if (abs(offsetY - y2) + abs(offsetX - x2) <= days)
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

    if (!solve(1e18)) {
        cout << -1;
        return 0;
    }

    ll lo = 0, hi = 1e18;

    while (lo < hi) {
        ll mid = lo + (hi - lo)/2;

        if (solve(mid))
            hi = mid;
        else
            lo = mid+1;
    }

    cout << lo;

    return 0;
}

/*
0 3
0 0
3
UDD
*/