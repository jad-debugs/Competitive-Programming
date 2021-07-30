#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 2e9;

    // guess starting = i 
    for (int i = 0; i < n; i++) {
        int sum = 0;
        queue<int> q;

        // need to mark rest as visited so we dont redo once we get to end
        for (int j = i, cnt = 0; cnt < n; cnt++, j = (j+1)%n) {
            for (int z = 0; z < arr[j]; z++)
                q.push(cnt);

            if (q.empty()) {
                sum = 2e9;
                break;
            }
            int fr = q.front();
            sum += (cnt - fr)*(cnt-fr);
            q.pop();
        }
        ans = min(ans, sum);
    }
    cout << ans;
}