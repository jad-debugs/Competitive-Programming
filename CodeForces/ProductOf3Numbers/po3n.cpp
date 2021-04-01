#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        // find smallest divisor
        int small = 0;
        for (int i = 2; i*i <= n; i++) {
            if (n%i==0) {
                small = i;
                break;
            }
        }
        if (!small) {
            cout << "NO\n";
            continue;
        }
        // second and third now
        int mid = 0, big = 0;
        for (int i = 2; i*i <= n/small; i++) {
            if (n/small%i==0 && i != small) {
                mid = i;
                big = n/small/mid;
                break;
            }
        }
        if (!mid || big == mid || big == 1 || big == small) {
            cout << "NO\n"; 
            continue;
        }
        cout << "YES\n";
        cout << small << ' ' << mid << ' ' << big << '\n';
    }
}
