#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    string paren; cin >> paren;

    int diff = 0, open = 0, close = 0, ans = 0;

    for (char c: paren) {
        if (c == '(') {
            diff++;
            open++;
        }
        else {
            diff--;
            close++;
        }
        if (diff <= 1) {
            open = 0;
        }
        if (diff <= -1) {
            ans = close;
            break;
        }
    }

    if (diff > 0) {
        ans = open;
    }

    cout << ans;

    return 0;
}
