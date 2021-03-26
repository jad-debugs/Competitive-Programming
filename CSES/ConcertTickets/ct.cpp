#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    multiset<int> ms;
    int n, m; cin >> n >> m;
   
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        ms.insert(a);
    }
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        auto p = ms.upper_bound(t);

        if(p == ms.begin())
            cout << "-1\n";
        else {
            cout << *(--p) << "\n";
            ms.erase(p);
        }        
    }
    
}
