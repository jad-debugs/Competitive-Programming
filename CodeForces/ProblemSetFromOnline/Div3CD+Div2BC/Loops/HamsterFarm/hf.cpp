#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k; cin >> n >> k;
    
    long long mod = 1e20, boxType = 1e20, numOfBox;

    for(long long i = 0; i < k; i++) {
        long long a; cin >> a;
        if (mod > n%a) {
            mod = n%a;
            boxType = i+1;
            numOfBox = n/a;
        } 
    }
    
    cout << boxType << " " << numOfBox;
    return 0;
} 
