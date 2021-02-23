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
 
ll n, k;
const int hi = 2e5;
int arr[hi];

bool solve(int median)
{
    ll moves = 0;
    for(int i = n/2; i < n; i++) {
        moves += max(0, median - arr[i]);
    }
    if(moves <= k)
        return true;
    return false;
}
 
void setIO(string name = "")
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    } 
}
 
 
int main()
{
    setIO();
 
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    
    ll least = 1;
    ll greatest = (int)2e9;

    while(least < greatest) {
        ll mid = least + (greatest - least + 1)/2;
        if(solve(mid))
            least = mid;
        else
            greatest = mid - 1;
    }
    cout << least;
    return 0;
}