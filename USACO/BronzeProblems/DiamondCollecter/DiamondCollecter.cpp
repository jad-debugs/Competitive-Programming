#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);

    int n, k, ans = 1, res = 0;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        ans = 1;
        for(int j = i+1; j < n; j++) {
            if(arr[j] <= arr[i] + k) {
                ans++; 
            }
        }
        if(ans > res)
            res = ans;
    }

    cout << res;

    return EXIT_SUCCESS;
}