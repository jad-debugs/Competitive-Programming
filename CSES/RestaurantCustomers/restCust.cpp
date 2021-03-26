#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n; cin >> n;
    map<int, int> cust;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cust[a] = 1;
        cust[b] = -1;
    }
    
    int ans = 0;
    int tmpA = 0;
    for(pair<int, int> x: cust) {
        tmpA += x.second;
        ans = max(ans, tmpA);
    }
    cout << ans;
}
