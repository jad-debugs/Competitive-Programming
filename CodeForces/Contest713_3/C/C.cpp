#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

bool isPal(string str) {
    const int n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] != str[n-i-1])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int zero, one; cin >> zero >> one;
        string str; cin >> str;

        int l = 0, r = (int)str.size()-1;
        bool flag = true;
        for (int i = 0; i <= r; i++) {
            if (str[i] == '0')
                zero--;
            else if (str[i] == '1')
                one--;
        }
        while (l <= r) {
            if (!flag)
                break;
            if (l == r) {
                if (str[l] != '?')
                    break;
                if (one >= zero) {
                    one--;
                    str[l] = '1';
                }
                else {
                    zero--;
                    str[l] = '0';
                }
            }
            else if (str[l] != '?' && str[r] != '?') {
                if (str[l] != str[r]) {
                    flag = false;
                }
            }
            else if (str[l] == '?' && str[r] == '?') {
                if (zero >= one && zero > 1) {
                    str[l] = '0';
                    str[r] = '0';
                    zero -= 2; 
                }
                else if (one > 1) {
                    str[l] = '1';
                    str[r] = '1';
                    one -= 2;
                }
                else
                    flag = false;
            }
            else if (str[l] == '?' && str[r] != '?') {
                if (str[r] == '1') {
                    if (one > 0) {
                        str[l] = '1';
                        one--;
                    }
                }
                else if (str[r] == '0') {
                    if (zero > 0) {
                        str[l] = '0';
                        zero--;
                    }
                }
                else
                    flag = false;
            }
            else if (str[l] != '?' && str[r] == '?') {
                if (str[l] == '1') {
                    if (one > 0) {
                        str[r] = '1';
                        one--;
                    }
                }
                else if (str[l] == '0') {
                    if (zero > 0) {
                        str[r] = '0';
                        zero--;
                    }
                }
                else
                    flag = false;
            }
            l++; r--;
        }
        if (!flag) {
            cout << "-1\n";
            continue;
        }
        if (zero == 0 && one == 0)
            cout << str << '\n';
        else
            cout << "-1\n";
    }
}
