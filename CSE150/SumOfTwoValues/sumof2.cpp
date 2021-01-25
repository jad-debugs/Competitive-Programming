#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long 

int main()
{
    ll n, target;
    cin >> n >> target;

    ll arr[n];
    map<ll, ll> pos;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    ll l = 0, r = n-1;

    sort(arr, arr+n);

    while(l != r) {
        ll sum = arr[l] + arr[r];
        if(sum == target) {
            cout << ++pos[arr[l]] << " " << ++pos[arr[r]];
            return 0;
        }
        else if(sum < target)
            l++;
        else
            r--;
    }
    cout << "IMPOSSIBLE";
}
