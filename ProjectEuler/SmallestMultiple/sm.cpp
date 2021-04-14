#include <iostream>
using namespace std;

const long long MX = 1e18;

bool check(long long x)
{
    for (int i = 1; i <= 20; i++) {
        if (x%i!=0)
            return false;
    }
    return true;
}

int main()
{
    for (long long i = 2520; i <= MX; i++) {
        if (check(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}

