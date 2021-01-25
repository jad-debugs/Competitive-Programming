#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--) {
        string s; cin >> s;

        if(s.size() < 10) {
            cout << "NO\n";
            continue;
        }

        bool lC = false, uC = false, d = false, sC = false;

        size_t size = s.size();

        if((s[0] >= 97 && s[0] <= 122) || (s[size-1] >= 97 && s[size-1] <= 122))
            lC = true;
        for(int i = 1; i < size-1; i++) {
            if(s[i] >= 97 && s[i] <= 122)
                lC = true;
            if(s[i] >= 65 && s[i] <= 90)
                uC = true;
            if(s[i] >= '0' && s[i] <= '9')
                d = true;
            if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '&' || s[i] == '?')
                sC = true;
        }

        if(lC && uC && d && sC)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}