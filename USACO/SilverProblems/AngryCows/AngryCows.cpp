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

vector<int> arr;
int n, k;

bool works(int r)
{
    int cnt = 0, last = 0, ans = 0;
    while (last < n) {
        ans++;
        cnt = last + 1;
        while (cnt < n && arr[cnt] - arr[last] <= r<<1)
            cnt++;
        last = cnt;
    }
    if (ans <= k)
        return true;
    return false;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main()
{
    setIO("angry");

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int small = 0, big = 2e6;

    while (small < big) {
        int mid = small + (big - small)/2;
        if (works(mid))
            big = mid;
        else
            small = mid + 1;
    }
    cout << small;
    return 0;
}
