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

    int len, sum;
    cin >> len >> sum;

    // annoying side test case messes up my algo i think
    if (len == 1 && sum == 0) {
        cout << sum << ' ' << sum;
        return 0;
    }

    if (len > 1 && sum == 0) {
        cout << "-1 -1";
        return 0;
    }

    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // finding largest is easy, use greatest possible when possible

    int greedy = 9;
    string mx = "";

    for (int i = 0; i < len; i++) {
        greedy = min(sum, greedy);
        sum -= greedy;
        mx += digits[greedy];
    }

    if (sum != 0) {
        cout << "-1 -1";
        return 0;
    }

    // reverse is answer, unless 0, then i need to find last !0 make it less 1

    string mn = "";

    for (int i = len - 1; i >= 0; i--)
        mn += mx[i];

    if (mx[len-1] == '0') {
        mn[0] = '1';
        for (int i = 1; i < len; i++) {
            if (mn[i] != '0') {
                mn[i] = digits[mn[i] - '1'];
                break;
            }
        }
    }

    cout << mn << ' ' << mx;

    return 0;
}
