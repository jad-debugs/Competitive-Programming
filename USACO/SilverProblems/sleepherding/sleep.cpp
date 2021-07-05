#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    // finding min
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n-1 && arr[i] + n-1 >= arr[j+1]) {
            j++;
        }
        cnt = max(cnt, j-i+1);
    }
    cnt = n-cnt;

    if ((arr[n-1] - arr[1] == n-2 && arr[1] - arr[0] > 2) || (arr[n-2] - arr[0] == n-2 && arr[n-1] - arr[n-2] > 2))
        cnt  = 2;

    cout << cnt << "\n";

    // max
    cout << arr[n-1] - arr[0] - min(arr[n-1] - arr[n-2], arr[1] - arr[0]) - n + 2;

    return 0;
}
