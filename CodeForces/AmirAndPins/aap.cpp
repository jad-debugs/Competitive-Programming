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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    int r, x1, y1, x2, y2; cin >> r >> x1 >> y1 >> x2 >> y2;
    double distance = sqrt(pow(x2-x1,2) + pow(y2-y1, 2));

    cout << ceil(distance/2/r);

    return 0;
}
