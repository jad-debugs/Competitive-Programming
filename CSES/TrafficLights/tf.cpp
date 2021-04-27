#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    multiset<int> lights;

    multiset<int> diff;
    diff.insert(n);
    lights.insert(0); lights.insert(n);

    for (int i = 0; i < k; i++) {
        int a; cin >> a;

        auto ptr = lights.upper_bound(a);
        int del = *ptr;
       
        diff.insert(del - a);

        ptr--;
        diff.insert(a - *ptr);

        del -= *ptr;
        diff.erase(diff.find(del));
        
        lights.insert(a);
        cout << *diff.rbegin();
        if (i + 1 < k)
            cout << ' ';
    }
}

