#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n, k;
bool bs(vector<ll> arr, ll guess)
{
    ll pf = 0;
    ll groups = 1;
    for (int idx = 0; idx < n; idx++) {
        if (pf + arr[idx] > guess) {
            pf = arr[idx];
            if (pf > guess) {
                return false;
                groups++;
                pf = 0;
            }
            groups++;
        } 
        else
            pf += arr[idx];
    } 
    return groups <= k;
}

int main()
{
    cin >> n >> k;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll small = 1, big = 1e16; // 10^9 * 2*10^5 is max
    while (small < big) {
        ll mid = small + (big - small)/2;
        if (bs(v, mid))
            big = mid;
        else
            small = mid + 1;
    }
    cout << big;
    return 0;
}
