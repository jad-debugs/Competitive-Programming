#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll t; cin >> t;
    
    while(t--) {
        ll n;
        cin >> n;
        if(((n & (n - 1)) == 0) && (n!=1))
                cout << "NO";
        else cout << "YES";
    }
    return 0;
}

