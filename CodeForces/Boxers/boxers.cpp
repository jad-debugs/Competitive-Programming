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
    setIO("");

    int n; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int small = 0;

    for (int i = 0; i < n; i++) {
        int &num = v[i];

        if (small < num-1) {
            num--;
            small = num;
        }
        else if (small < num)
            small = num;
        else if (small < num+1) {
            num++;
            small = num;
        }
    }

    sort(v.begin(), v.end());

    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1])
            ans++;
    }

    cout << ans;

    return 0;
}
