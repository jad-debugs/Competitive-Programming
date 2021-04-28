/*
ID: jadDebugs
TASK: namenum
LANG: C++                 
*/

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
    setIO("namenum");

    ifstream fp("dict.txt");

    vector<string> names; 
    string st;
    while (fp >> st)
        names.push_back(st);

    map<char, int> map; // gonna brute force cuz im too lazy to think rn
    map['A'] = 2;
    map['B'] = 2;
    map['C'] = 2;
    map['D'] = 3;
    map['E'] = 3;
    map['F'] = 3;
    map['G'] = 4;
    map['H'] = 4;
    map['I'] = 4;
    map['J'] = 5;
    map['K'] = 5;
    map['L'] = 5;
    map['M'] = 6;
    map['N'] = 6;
    map['O'] = 6;
    map['P'] = 7;
    map['R'] = 7;
    map['S'] = 7;
    map['T'] = 8;
    map['U'] = 8;
    map['V'] = 8;
    map['W'] = 9;
    map['X'] = 9;
    map['Y'] = 9;

    vector<string> ans;
    string n; cin >> n;

    for (string str: names) {
        bool sol = true;
        if (str.size() != n.size())
            continue;
        for (int i = 0; i < (int)str.size(); i++) {
            if (n[i] - '0' != map[str[i]]) {
                sol = false;
                break;
            }
        }
        if (sol)
            ans.push_back(str);
    }

    sort(begin(ans), end(ans));
    for (string a: ans)
        cout << a << '\n';
    if (ans.size() == 0)
        cout << "NONE\n";
    return 0;
}
