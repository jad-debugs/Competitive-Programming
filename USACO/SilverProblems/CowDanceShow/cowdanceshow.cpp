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

int n, t;
const int hi = 2e5;
int arr[hi];

bool isValid(int k)
{
    int timePass = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if(pq.size() == k) {
            timePass = pq.top(); // equal not += because you it is time passed
            pq.pop();
        }
        if(timePass + arr[i] > t)
            return false;
        // we are pushing time passed in general, not in the moment
        pq.push(timePass + arr[i]);
    }
    return true;
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
    setIO("cowdance");

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 1;
    int high = n;

    while(low != high) {
        int mid = low + (high-low)/2;
        if(isValid(mid))
            high = mid;
        else
            low = mid+1;
    }
    cout << low;
    return 0;
}
