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

ll groupsForm(ll a)
{
    return (a*(a-1)/2LL);
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
    setIO("");

    ll n, g; cin >> n >> g;

    // greedy min
    if (n%g == 0)
        cout << groupsForm(n/g) * g << ' ';
    else {
        ll front = n/g;
        ll back = n%g;
        cout << groupsForm(front) * (g - back) + groupsForm(front+1) * back << ' ';
    }

    // greedy max
    cout << groupsForm(n - (g-1));

    return 0;
}

// greedy
// max is found by putting most into a group
// least is found by putting even amount into each group
/*
5 3
1 1 111
7 2
11111 1
11 11 11 1
*/