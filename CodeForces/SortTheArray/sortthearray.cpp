#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> orig(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> orig[i];
        sorted[i] = orig[i];
    }

    sort(sorted.begin(), sorted.end());

    int left = 0, right = 0;
    bool start = false;

    for (int i = 0; i < n; i++) {
        if ((orig[i] != sorted[i]) && !start) {
            start = true;
            left = i;
            right = i;
        }
        else if ((orig[i] != sorted[i]) && start) {
            right = i;
        }
    }

    reverse(orig.begin()+left, orig.begin()+right+1);

    bool works = true;

    for (int i = 0; i < n; i++) {
        if (orig[i] != sorted[i]) {
            works = false;
            break;
        }
    }

    if (!works)
        cout << "no";
    else {
        cout << "yes\n";
        cout << left+1 << ' ' << right+1;
    }

    return 0;
}