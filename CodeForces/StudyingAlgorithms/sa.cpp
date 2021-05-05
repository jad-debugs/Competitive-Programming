#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, t; cin >> n >> t;
    int arr[n] = {0};

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    
    int time = 0, i = 0;
    for (; i < n; i++) {
        if (time + arr[i] <= t)
            time += arr[i];
        else
            break;
    }
    cout << i;
}
