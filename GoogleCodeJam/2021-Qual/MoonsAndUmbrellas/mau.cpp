#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        int x, y; cin >> x >> y;

        string s; cin >> s;
        int sz = s.size();
        
        char fro = 'X';
        
        int ans = 0;

        for (int i = 0; i < sz; i++) {
            if (fro == 'C' && s[i] == 'J')
                ans += x;
            if (fro == 'J' && s[i] == 'C')
                ans += y;
            if (s[i] != '?')
                fro = s[i];
        }

        cout << ans << '\n';
    }
}

