#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "#" << z << ": ";
       
        int n; cin >> n;
        vector<string> strs(n);
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> strs[i]; 
            nums[i] = stoi(strs[i]); 
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1])
                continue;
            string a = strs[i-1];
            string b = strs[i];
            const int sz = b.size();
            
            for (int i = 1; i < (int)a.size(); i++) {
                if (i > sz) {
                    
                }      
            }
        }
        cout << ans << '\n';  
    }
}
