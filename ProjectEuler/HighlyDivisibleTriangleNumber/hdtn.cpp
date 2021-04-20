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

bool done(ll n)
{
    int f = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n%i==0)
            f+=2;
        if (i*i == n)
            f--;
    }
    return f > 500;
}


int main()
{
    ll i = 1;
    for (ll cnt = 1; !done(i); i = (cnt+1)*(cnt+2)/2, cnt++)
        ;
    cout << i;
    return 0;
}
