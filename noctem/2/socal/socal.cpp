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
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("distancing");

    int n; cin >> n;

    vector<int> ducks(n);

    int prev = -100, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> ducks[i];
    }

    sort(ducks.begin(), ducks.end());

    for (int i = 0; i < n; i++) {
        int a = ducks[i];
        if (prev + 6 <= a)
            prev = a;
        else {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
