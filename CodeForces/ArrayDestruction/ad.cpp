#include <bits/stdc++.h>
using namespace std;

vector<int> check(int n, vector<int> arr, int x)
{
    multiset<int> ms;
    vector<int> ans;

    for (int x: arr)
        ms.insert(x);

    for (int i = 0; i < n; i++) {
        auto it = ms.end();
        it--;
        int b = x - *it;
        ms.erase(it);
        auto it2 = ms.find(b);

        if (it2 == ms.end())
            return {};
        ans.push_back(x-b);
        ans.push_back(b);
        x = max(x-b, b);
        ms.erase(it2);
    }
    return ans; 
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr(n*2);

        for (int i = 0; i < n*2; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());

        bool works = false;
        
        for (int i = 0; i < 2*n-1; i++) {
            int x = arr[i] + arr[2*n-1];

            vector<int> ans = check(n, arr, x);
            if (ans.size()) {
                cout << "YES\n" << x << "\n";
                for (int j = 0; j < n; j++)
                    cout << ans[2*j] << ' ' << ans[2*j+1] << '\n';
                works = true;
                break;
            }
        }
        if (!works)
            cout << "NO\n";
    }
}
