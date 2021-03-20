// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <iostream>
#include <utility>
#include <algorithm>

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

    int n; cin >> n;
    
    int curDay = 0;
    
    pair<int, int> arr[n]; 
    
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr+n);
    
    for (int i = 0; i < n; i++) {
        int a = arr[i].f;
        int b = arr[i].s;
        if (!curDay)
            curDay = b;
        else if (b < curDay)
            curDay = a;
        else
            curDay = b;
    }
    cout << curDay;
    return 0;
}
