// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}


int main()
{
    setIO("hps");

    int n; cin >> n;

    int arr[3][1000002] = {0};

    for(int i = 1; i <= n; i++) {
        char a; cin >> a;
        if(a == 'P') {
            arr[0][i] = arr[0][i-1];
            arr[1][i] = arr[1][i-1] + 1;
            arr[2][i] = arr[2][i-1];
        }
        if(a == 'S') {
            arr[0][i] = arr[0][i-1];
            arr[1][i] = arr[1][i-1];
            arr[2][i] = arr[2][i-1] + 1;
        }
        else if (a == 'H') {
            arr[0][i] = arr[0][i-1] + 1;
            arr[1][i] = arr[1][i-1];
            arr[2][i] = arr[2][i-1];
        }
    }
    

    int ans = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            for(int a = 1; a <= n; a++) {
                ans = max(ans, arr[i][a] + arr[j][n] - arr[j][a]);
            }
        }
    }
    cout << ans;
    return 0;
}
