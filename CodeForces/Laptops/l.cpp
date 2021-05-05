#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main()
{
    int n; cin >> n;
    vector<pair<int, int> > arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].f >> arr[i].s;
    }
    sort(begin(arr), end(arr));

    int high = arr[0].s;
    int f = arr[0].f;
    bool sol = false;
    for (int i = 0; i < n; i++) {
        if (f == arr[i].f)
            continue;
        if (high > arr[i].s) {
            sol = true;
            break;
        }
        else {
            high = arr[i].s;
            f = arr[i].f;
        }
    }
    if (sol)
        cout << "Happy Alex";
    else
        cout << "Poor Alex";
    return 0;
}
