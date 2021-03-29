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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

pii solve(vector<pii> &arr, int idxBad, int target, int n)
{
    int l = 0, r = n-1;
    while (l < r) {
        if (l == idxBad) {
            l++; continue;
        }
        if (r == idxBad) {
            r--; continue;
        }
        int sum = arr[l].f + arr[r].f;
        if (sum == target) {
            pii tmp(l, r);
            return tmp;
        }
        if (sum < target)
            l++;
        if (sum > target)
            r--;
    }
    return {-1, -1};
}

int main()
{
    setIO("");

    int n, target; cin >> n >> target;

    if (n < 3) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<pii> arr;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back({a, i+1});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        pii test = solve(arr, i, target - arr[i].f, n);
        if (test.f != -1) {
            cout << arr[test.f].s << ' ' << arr[test.s].s << ' ' << arr[i].s;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
