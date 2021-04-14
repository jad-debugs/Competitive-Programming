#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MX = 2e6;
vector<bool> primes(MX, 1);

int main() 
{ 
    for (ll i = 2; i*i <= MX; i++) {
        if (primes[i]) {
            for (ll j = i*i; j <= MX; j += i)
                primes[j] = 0;
        }
    }
    ll pN = 0;
    for (int i = 2; i <= MX; i++) {
        if (primes[i])
            pN += i;
    }
    cout << pN;
    return 0;
}
