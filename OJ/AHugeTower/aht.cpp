#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 1e9+9;

int main()
{
    int n, d; cin >> n >> d;

    vector<int> arr(n);
    vector<long long> dp(n);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    for (int r = 1, l = 0; r < n; r++) {
        while (l < r && arr[l] + d < arr[r])
            l++;
        dp[r] = ((r-l+1) * dp[r-1]) % mod;
        dp[r] %= mod;
    }

    cout << dp[n-1];
}

