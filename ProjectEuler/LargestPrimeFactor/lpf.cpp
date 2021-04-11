#include <iostream>
using namespace std;
#define ll long long

void sieve(ll n)
{
    ll mx = -1;
    while ((n&1)==0) {
        mx = 2;
        n >>= 1;
    }

    for (int i = 3; i*i <= n; i+=2) {
        while (n%i==0) {
            mx = i;
            n /= i;
        }
    }
    cout << (n > 2 ? n : mx);
}

int main()
{
    sieve(600851475143);
}
