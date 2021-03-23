// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

// learned from gfg, then slightly modified
void primeFactors(int n, int &even, int &odd)  
{
    while (n % 2 == 0) {  
        even++; 
        n /= 2;  
    }
    for (int i = 3; i <= sqrt(n); i += 2) {   
        while (n % i == 0) {  
            odd++;  
            n /= i;  
        }  
    }   
    if (n > 2)  
        odd++;  
}

bool isprime(int n){
    for(int i = 2; i < min((int)1e5, n); i++)
        if(n % i == 0)
            return 0;
    return 1;
}

void setIO(string name = "") {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        // possible ways for fastest finger to win
        if (n == 1)
            cout << "FastestFinger\n";
        else if (n%2 == 1)
            cout << "Ashishgup\n";
        else if ((n & (n - 1)) == 0 && n > 2)
            cout << "FastestFinger\n";
        else if (isprime(n/2) && n % 4 != 0 && n > 2)
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
    }

    return 0;
}
