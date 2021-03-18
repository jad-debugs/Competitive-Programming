#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        map<int, int> map;
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            map[arr[i]]++;
        }
        sort(arr.begin(), arr.end());

        vector<int> dups;
        
        for (int i = 0; i < n; i++) {
            if (map[arr[i]] == 1)
                cout << arr[i] << ' ';
            else
                dups.push_back(arr[i]);
            map[arr[i]]--;
        }
        for (int i: dups)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
