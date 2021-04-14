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

bool palindrome(int num)
{
    string str = to_string(num);
    int sz = str.size();
    int l = 0, r = sz-1;
    while (l < r) {
        if (str[l] != str[r])
            return false;
        l++; r--;
    }
    return true;
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

    int ans = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            if (palindrome(i*j))
                ans = max(ans, i*j);
        }
    }

    cout << ans;
    return 0;
}
