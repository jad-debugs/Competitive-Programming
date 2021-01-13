#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    
    int ans[t];

    for(int a = 0; a < t; a++) {
        int n, k, d; cin >> n >> k >> d;
        int problems = 0;

        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            problems += tmp;
        } 
        
        ans[a] = min(problems/k, d); 
    }
    
    for(int i = 0; i < t-1; i++)
        cout << ans[i] << "\n";
    cout << ans[t-1];
    return 0;
}
