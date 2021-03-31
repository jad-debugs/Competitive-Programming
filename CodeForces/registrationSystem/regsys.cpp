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

    set<string> names;
    map<string, int> numFound;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        if (names.count(str)) {
            cout << str << ++numFound[str] << '\n';
        }
        else {
            cout << "OK\n";
            names.insert(str);
        }
    }

    return 0;
}
