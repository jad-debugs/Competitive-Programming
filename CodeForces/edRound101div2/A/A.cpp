#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        int q = 0;
        int sz = str.size();
        for(char ch: str) {
            if(ch == '?')
                q++;
        }
        if(str[0] == ')')
            cout << "NO" << "\n";
        else if(str[sz-1] == '(')
            cout << "NO" << "\n";
        else if(q%2 == 1)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
}
