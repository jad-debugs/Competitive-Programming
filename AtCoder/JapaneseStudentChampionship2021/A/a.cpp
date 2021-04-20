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

    double x, y, z; cin >> x >> y >> z;

    cout << ceil(y*z/x) - 1;

    return 0;
}
