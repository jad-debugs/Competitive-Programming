#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long 

int main()
{
    int n, target;
    cin >> n >> target;

    map<int, int> pos;

    int arr[n];
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(pos.count(a))
            pos[-a] = i+1;
        else
            pos[a] = i+1;
        arr[i] = a;
    }

    sort(arr, arr+n);

    int l = 0, r = n-1;

    while(l < r) {
        int sum = arr[l] + arr[r];

        if (sum < target)
            l++;
        else if (sum > target)
            r--;
        else {
            int fr = pos[arr[l]];
            int br = pos[arr[r]];
            if (fr != br)
                cout << fr << " " << br;
            else
                cout << fr << " " << pos[-arr[r]];
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
