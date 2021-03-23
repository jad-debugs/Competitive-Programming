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

bool cmp(int a, int b)
{
    return a > b;
}

void setIO(string name = "") {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int n; cin >> n;
    string s; cin >> s;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        if (a == 4) {
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(3);
        }
        else if (a == 6) {
            ans.push_back(5);
            ans.push_back(3);
        }
        else if (a == 8) {
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(7);
        }
        else if (a == 9) {
            ans.push_back(2);
            ans.push_back(3);
            ans.push_back(3);
            ans.push_back(7);
        }
        else if (a != 0 && a != 1)
            ans.push_back(a);
    }
    sort(ans.begin(), ans.end(), cmp);

    for (int x: ans)
        cout << x;
    return 0;
}
