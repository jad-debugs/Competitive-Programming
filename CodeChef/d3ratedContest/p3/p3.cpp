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

bool cmp(pii a, pii b)
{
    if(a.f == b.f)
        return a.s < b.s;
    return a.f > b.f;
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

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        pii arr[n];

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            arr[i] = {a, i};
        }

        sort(arr, arr+n, cmp);
        ll hours = 1;
        vector<int> wait(n);
        for(pii val: arr) {
            wait[val.s] = hours;
            hours++;
        }

        for(int i = 0; i < n; i++) {
            cout << wait[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
