#include <iostream>
using namespace std;

int main()
{
   int n; cin >> n;

   int arr[n];

   for(int i = 0; i < n; i++) {
       cin >> arr[i];
   }
   
   int q; cin >> q;
   int ans[q];
   int ig; cin >> ig;
   
   for(int a = 0; a < q; a++) {
       int l, r, x; cin >> l >> r >> x; 
       int tmpA = 0;
       for(int i = l-1; i < r; i++) {
           if(arr[i] == 0) {
               tmpA += x;
           }
           else tmpA += arr[i];
        }
        ans[a] = tmpA;
   }
   
    for(int i = 0; i < q-1; i++) {
        cout << ans[i] << "\n";
    }
    cout << ans[q-1] << "\n";
   return EXIT_SUCCESS; 
}
