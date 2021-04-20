#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll sim(ll start)
{
    ll ans = 0;
    while (start != 1) {
        if (start%2 == 0)
           start /= 2;
        else
            start = start*3 + 1;
        ans++;
    }
    return ans+1;
}

int main()
{
    ll ans = 0, longest = 0;
    for (ll i = 357; i <= 1000000; i++) {
        ll tmp = sim(i);
        if (tmp > longest) {
            longest = tmp;
            ans = i;
        }
    }
    cout << ans;
}
