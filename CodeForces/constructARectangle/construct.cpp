#include <bits/stdc++.h>
using namespace std;

bool works(int a, int b, int c)
{
    if (a == b+c || b == a+c || c == a+b)
        return true;
    if ((a%2==0 && b == c) || (b%2==0 && a == c) || (c%2==0 && b == a))
        return true;
    return false;
}

int main()
{
    int t; cin >> t;

    while (t--) {
        int a, b, c; cin >> a >> b >> c;

        if (works(a, b, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}