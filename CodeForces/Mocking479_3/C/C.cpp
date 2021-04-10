#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x; cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int ans;
    if (x==0)
        ans = arr[0]-1;
    else
        ans = arr[x-1];
    int newX = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= ans)
            newX++;
    }
    if (ans < 1 || newX != x)
        cout << "-1";
    else
        cout << ans;
}
