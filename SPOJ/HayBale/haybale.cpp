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
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("");

    int n, k; cin >> n >> k;

    int arr[n+1] = {0};

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        arr[a]++;
        arr[b+1]--;
    }
    int pf = 0;
    for (int i = 0; i < n; i++) {
        pf += arr[i];
        arr[i] = pf;
    }

    sort(arr, arr+n);

    cout << arr[n/2];

    return 0;
}
