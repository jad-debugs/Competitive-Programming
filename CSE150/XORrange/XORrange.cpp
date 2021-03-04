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

    int n, q;
    cin >> n >> q;
    int arr[n+1] = {0};

    int pf = 0;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pf ^= a;
        arr[i] = pf;
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << ((arr[b])^(arr[a-1])) << "\n";
    }

    return 0;
}
