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

        for (int i = 0; i < sz; i++) {
            if (s[i] == '?') {
                if (i > 0 && i < sz-1) {
                    if (s[i-1] != s[i+1]) {
                        if (s[i-1] == 'C') {
                            if (x < y)
                                s[i] = 'J';
                            else
                                s[i] = 'C';
                        }
                        else {
                            if (y < x)
                                s[i] = 'C';
                            else
                                s[i] = 'J';
                        }
                    } 
                    else
                        s[i] = s[i-1];
                }
                else if (i == 0 && sz != 1)
                    s[i] = s[i+1];
                else if (i == sz - 1 && sz != 1)
                    s[i] = s[i-1];
                else
                    s[i] = 'J'; // either doesnt matter
            }
        }
        int ans = 0;
        for (int i = 0; i < sz-1; i++) {
            if (s[i] == 'C' && s[i+1] == 'J')
                ans += x;
            else if(s[i] == 'J' && s[i+1] == 'C')
                ans += y;
        }
        cout << ans << '\n';
    }
}
