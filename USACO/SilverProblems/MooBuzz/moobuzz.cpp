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
    setIO("moobuzz");

    ll n; cin >> n;
    ll idxAns = n - ((n-1)/8 * 8);
    ll cnt = 0;
    ll i = 1+15L*((n-1)/8);
    for(; i <= i+14; i++) {
        if((i >= 3 && i%3 == 0) || (i >= 5 && i%5 == 0))
            continue;
        cnt++;
        if(cnt == idxAns) {
            cout << i;
            return 0;
        }
    }
    
    return 0;
}
