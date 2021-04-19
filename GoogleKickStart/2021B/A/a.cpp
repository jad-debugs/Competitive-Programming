#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "CASE #" << z << ": ";

        int n; cin >> n;
        string s; cin >> s;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i-1] >= s[i])
                cur = i;
            if (i != n-1)
                cout << i - cur + 1 << ' ';
            else
                cout << i - cur + 1;
        }
        cout << '\n';
    }
}
