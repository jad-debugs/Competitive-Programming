#include <iostream>
using namespace std;

bool oddDiv(long long n)
{
    if (n != 0 && ((n&(n-1)) == 0)) 
        return false;
    return true;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << (oddDiv(n) ? "YES\n": "NO\n");
    }
}