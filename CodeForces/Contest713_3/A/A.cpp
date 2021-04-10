#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int> > arr(n);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            arr[i] = make_pair(a, i+1);
        }
        sort(arr.begin(), arr.end());
        if (arr[0].first == arr[1].first)
            cout << arr[n-1].second;
        else
            cout << arr[0].second;
        cout << '\n';
    }
    return 0;
}
