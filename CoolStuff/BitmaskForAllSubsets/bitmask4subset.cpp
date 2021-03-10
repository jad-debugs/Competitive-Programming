#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // printing out subsets
    // mask as 0 will always be off bit
    cout << "empty subset\n"; // lol

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int idx = 0; idx < n; idx++) {
            int bin = 1 << idx;
            // check if on bit at mask
            if (mask & bin)
                cout << arr[idx] << ' ';
        }
        cout << "\n";
    }
}