#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

ll n, t;

bool bs(vector<ll> arr, ll test)
{
    ll products = 0;
    for (int i = 0; i < n; i++) {
        products += test/arr[i];
        if (products >= t)
            break;
    }
    return products >= t;
}

int main()
{
    cin >> n >> t;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll small = 1, big = 1e18;
    while (small < big) {
        ll mid = small + (big-small)/2;
        if (bs(arr, mid))
            big = mid;
        else
            small = mid + 1;
    }
    cout << big;
    return 0;
}

