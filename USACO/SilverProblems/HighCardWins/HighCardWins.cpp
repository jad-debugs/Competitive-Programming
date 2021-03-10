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
    setIO("highcard");

    int n; cin >> n;

    map<int, bool> mS;
    vector<int> second;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mS[a] = true;
        second.push_back(a);
    }
    sort(second.begin(), second.end());
    vector<int> first;

    for (int i = 1; i <= 2*n; i++) {
        if (!mS[i])
            first.push_back(i);
    }

    int ptr1 = 0, ptr2 = 0;

    int ans = 0;

    while (ptr1 != n && ptr2 != n) {
        if (first[ptr1] > second[ptr2]) {
            ans++;
            ptr2++;
            ptr1++;
        }
        else
            ptr1++;
    }
    cout << ans;
    return 0;
}
