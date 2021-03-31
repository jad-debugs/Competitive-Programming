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

    int lastOdd = 0, lastEven = 0, n;
    int cntEven = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i]%2 == 0) {
            lastEven = i;
            cntEven++;
        }
        else
            lastOdd = i;
    }

    if (cntEven == 1)
        cout << lastEven+1;
    else
        cout << lastOdd+1;
    return 0;
}
