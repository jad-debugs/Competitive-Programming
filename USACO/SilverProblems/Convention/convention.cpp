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

int hi = 2e5;

int n, b, c;

bool works(int t, vector<int> arr)
{
    int tmpB = 0;
    int idx = 0;
    for(;;) {

        if (tmpB > b)
            return false;
        if (idx >= n)
            return true;

        int tmpidx;

        // parenthesis just to help me imagine
        tmpidx += upper_bound(arr.begin()+idx, arr.end(), arr[idx] + t) - (arr.begin()+idx);
        tmpidx = min(tmpidx, c);
        idx += tmpidx;

        tmpB++;

    }
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
    setIO("convention");

    cin >> n >> b >> c;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 0, r = 2e9;

    while (l < r) {
        int mid = l + (r-l)/2;

        if (works(mid, arr))
            r = mid;
        else
            l = mid+1;
    }
    cout << l;
    return 0;
}
