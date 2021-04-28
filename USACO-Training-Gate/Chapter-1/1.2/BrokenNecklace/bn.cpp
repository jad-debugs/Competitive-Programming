/*
ID: jadDebugs
TASK: beads
LANG: C++  
*/

#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
string necklace;

int sub(int l)
{
    int rL = l;
    int r = l;
    if (necklace[l] == 'w') {
        while (necklace[l] == 'w' && l < n)
            l++;
    }
    while (r < l+n && (necklace[r] == necklace[l] || necklace[r] == 'w'))
        r++;
    res += r - rL;

    return r;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main()
{
    setIO("beads");

    cin >> n;
    cin >> necklace;
    necklace += necklace; // wrap around
    
    int ans = 0;
    for (int l = 0; l < n; l++) {
        sub(sub(l));
        ans = max(ans, min(res, n));
        res = 0;
    }
    cout << ans << '\n';
}
