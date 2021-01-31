// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

void solve()
{
    ;
}

int main()
{
    //setIO();

    int n, m, k; cin >> n >> m >> k;

    int apartments[n], people[m];

    for(int i = 0; i < n; i++) {
        cin >> apartments[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> people[i];
    }

    sort(apartments, apartments+n);
    sort(people, people+m);

    int a = 0, p = 0;

    int ans = 0;

    while(a < n && p < m) {
        if(abs(apartments[a] - people[p]) <= k) {
            a++;
            p++;
            ans++;
        }

        else if (people[p] > apartments[a])
            a++;
        else if(people[p] < apartments[a]) 
            p++;
    }
    cout << ans;
    return 0;
}