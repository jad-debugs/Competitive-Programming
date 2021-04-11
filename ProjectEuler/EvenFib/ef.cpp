#include <iostream>
using namespace std;

const long long MX = 4e6;

int main()
{
    long long p1 = 1, p2 = 2, ans = 0;
    while (true) {
        if (p1 < MX) {
            if ((p1&1) == 0)
                ans += p1;
        }
        else
            break;
        long long tmp = p1+p2;
        p1 = p2;
        p2 = tmp;
    }
    cout << ans;
}
