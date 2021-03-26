#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";
        
        int n; cin >> n;
        vector<int> v(n);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int cost = 0;
        for (int i = 0; i < n-1; i++) {
            int mn = 101;
            int idx = 0;

            for (int j = i; j < n; j++) {
                if (v[j] < mn) {
                    mn = v[j];
                    idx = j;
                }
            }
            
            cost += idx - i + 1;
            reverse(v.begin()+i, v.begin()+idx+1);

            /*cout << '\n';
            cout << "We just added " << idx - i + 1 << " to the cost, heres the array";
            cout << '\n';*/
            
        }
        cout << cost << '\n';
    }
    return 0;
}
