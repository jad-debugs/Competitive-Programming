#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i];
    
    multiset<int> towers;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        towers.insert(a);
    }

    int ans = 0;
    for (int x: cities) {
        int left = 2e9, right = 2e9;
        auto ptr = towers.upper_bound(x);    
        if (ptr != towers.end())
            right = *ptr - x;
        if (ptr != towers.begin()) {
            ptr--;
            left = x - *ptr;
        }
        ans = max(ans, min(left, right));
    }

    cout << ans;
}

