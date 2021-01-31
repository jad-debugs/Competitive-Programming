#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int t; cin >> t;
 
    while(t--) {
        int n, d; cin >> n >> d;
 
        int arr[n];
        int maxN = 0;
 
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            string ans = "NO\n";
            for(int j = 1; j <= 1000; j++) {
                if((d*j <= arr[i]) && (((arr[i] - d*j)%10 == 0) || ((arr[i] - d*j)%100)%10 == d ) ) {
                    ans = "YES\n";
                    break;
                }
            }
            cout << ans;
        }
 
 
    }
 
    return 0;
}
