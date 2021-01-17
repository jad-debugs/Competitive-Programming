#include <iostream>
#include <algorithm>
using namespace std;

struct Time {
    int l, r;
};

bool cmp(Time a, Time o) {
    return a.r < o.r;
}

int main()
{
    int t; cin >> t;

    Time arr[t];

    for(int i = 0; i < t; i++) {
        cin >> arr[i].l >> arr[i].r;
    }

    sort(arr, arr+t, cmp);

    int l = -1;

    int ans = 0;

    for(Time u : arr) {
        if(u.l >= l) {
            ans++;
            l = u.r;
        }
    }
    cout << ans;
    return 0;
}