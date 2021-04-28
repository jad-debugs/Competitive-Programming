/* 
ID: jadDebugs
TASK: transform
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n;
multiset<pii> org;
multiset<pii> prime;
multiset<pii> horiz;

bool hor()
{
    bool sol = true;
    for (pii p: horiz) {
        if (prime.find(p) == prime.end()) {
            sol = false;
            break;
        }
    }
    if (horiz.size() != prime.size())
        return false;
    return sol;
}

bool nine(multiset<pii> primeT)
{
    bool sol = true;
    for (pii p: primeT) {
        pii tmp = {p.s, n - p.f - 1};
        if (prime.find(tmp) == prime.end()) {
            sol = false;
            break;
        }
    }
    if (primeT.size() != prime.size())
        return false;
    return sol;
}
bool eight(multiset<pii> primeT)
{
    bool sol = true;
    for (pii p: primeT) {
        pii tmp = {n-p.f-1, n-p.s-1};
        if (prime.find(tmp) == prime.end()) {
            sol = false;
            break;
        }
    }
    if (primeT.size() != prime.size())
        return false;
    return sol;
}
bool two(multiset<pii> primeT)
{
    bool sol = true;
    for (pii p: primeT) {
        pii tmp = {n - p.s - 1, p.f};
        if (prime.find(tmp) == prime.end()) {
            sol = false;
            break;
        }
    }
    if (primeT.size() != prime.size())
        return false;
    return sol;
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
    setIO("transform");

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '@') {
                org.insert({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '@')
                prime.insert({i, j});
        }
    }
    bool noC = (prime.size() == org.size());
    for (pii p: org) {
        if (prime.find(p) == prime.end()) {
            noC = false;
            break;
        }
    }
    
    if (nine(org)) {
        cout << 1 << '\n';
        return 0;
    }
    if (eight(org)) {
        cout << 2 << '\n';
        return 0;
    }
    if (two(org)) {
        cout << 3 << '\n';
        return 0;
    }
    
    for (pii p: org)
        horiz.insert({p.f, n - 1 - p.s});
    if (hor()) {
        cout << 4 << '\n';
        return 0;
    }
    if (nine(horiz) || eight(horiz) || two(horiz)) {
        cout << 5 << '\n';
        return 0;
    }
    if (noC) {
        cout << 6 << '\n';
        return 0;
    }

    cout << 7 << '\n';

    return 0;
}
