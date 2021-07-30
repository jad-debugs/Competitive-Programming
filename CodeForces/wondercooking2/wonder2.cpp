#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        map<int, int> map;
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            arr.push_back(a);
            map[a]++;
        }
 
        int mx = 0, indiv = 0;
        set<int> set;

        for (auto p: map) {
            if (p.second >= k) {
                map[p.first] = 0;
                mx++;
                v.push_back(p.first);
            }
            else {
                indiv++;
                set.insert(map[p.first]);
            }
        }
 
        mx += indiv/k;

        vector<int> ans;

        int cur = 1;

        for (int i = 0; i < n; i++) {
            if (set.find(arr[i]) != set.end()) {
                ans.push_back(cur);
                cur++;
                if (cur-1 == mx)
                    cur = 1;
            }
            else if (map[arr[i]] != 0) {
                ans.push_back(map[arr[i]]);
                if (map[arr[i]] > 0)
                    map[arr[i]]++;
                if (map[arr[i]]-1 == mx)
                    map[arr[i]] = 0;
            }
        }
        for (int i = 0; i < n-1; i++) {
            cout << ans[i] << ' ';
        }
        cout << ans[n-1] << '\n';
    }
}