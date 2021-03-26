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

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

void printP(int n, char c)
{
    for(int i = 0; i < n; i++) {
        cout << c;
    }
}

void solve(string s)
{
    const int sz = s.size();

    printP(s[0] - '0', '(');
    for(int i = 0; i < sz; i++) {
        // behind parenthesis
        if(i != 0) {
            printP((s[i] - '0') - (s[i-1] - '0'), '(');
        }
        cout << s[i];
        // front parenthesis
        if(i != sz - 1) {
            printP((s[i] - '0') - (s[i+1] - '0'), ')');
        }
    }

    printP(s[sz-1] - '0', ')');
    cout << "\n";
}

int main()
{
    setIO();

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        string x; cin >> x;
        cout << "Case #" << i << ": "; solve(x);
    }

    return 0;
}
