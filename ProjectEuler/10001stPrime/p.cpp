#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MX = 1e8;
vector<bool> primes(MX, 1);

int main() 
{ 
    for (ll i = 2; i*i <= MX; i++) {
        if (primes[i]) {
            for (ll j = i*i; j <= MX; j += i)
                primes[j] = 0;
        }
    }
    int pN = 0;
    for (int i = 2; i <= MX; i++) {
        if (primes[i])
            pN++;
        if (pN == 10001) {
            cout << i;
            break;
        }

    }
    return 0;
}
