#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b; 
        string str; cin >> str;
        int n = a+b;

        for (int i = 0; i < n; i++) {
            if (str[i] == '?')
                str[i] = str[n-i-1];
        }

        a -= count(str.begin(), str.end(), '0');
        b -= count(str.begin(), str.end(), '1');
        
        for (int l = 0, r = n-1; l <= r; l++, r--) {
            if (l != r && str[l] == '?') {
                if (a > 1) {
                    str[l] = str[r] = '0';
                    a -= 2;
                }
                else if (b > 1) {
                    str[l] = str[r] = '1';
                    b -= 2;
                }
            }
            else if (str[l] == '?') {
                if (a > 0) {
                    str[l] = '0';
                    a--;
                }
                else {
                    str[l] = '1';
                    b--;
                }
            }
        }
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (a == 0 && b == 0 && rev == str)
            cout << str << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
