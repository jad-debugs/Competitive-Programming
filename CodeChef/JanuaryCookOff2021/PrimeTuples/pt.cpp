#include <bits/stdc++.h>
using namespace std;

void printTwinPrime(int n) 
{
    long long ans = 0;

    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) { 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        }
    }
    for (int p = 2; p <= n - 2; p++) 
        if (prime[p] && prime[p + 2]) 
            ans++;  
    cout << ans;
}
int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        printTwinPrime(n);
    }
}

/*bool checkPrime(vector<int> primes, int n) {
    for(int i = 3; i <= n; i++) {
        bool flag = true;
        for(int j: primes) {
            if(i%j==0) {
                flag = false;
                break;
            } 
        }
        if(flag) primes.push_back(i);
    } 
}*/