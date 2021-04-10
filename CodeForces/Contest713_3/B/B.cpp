#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x1, y1, x2, y2;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char x; cin >> x;
                if (x == '*') {
                    if (!flag) {
                        x1 = i;
                        y1 = j;
                        flag = true;
                    }
                    else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        int ax1, ay1, ax2, ay2;
        // case of opposite corner
        if (x1 != x2 && y1 != y2) {
            ax1 = x1;
            ay1 = y2;
            ax2 = x2;
            ay2 = y1;
        } // now diff x, same y
        else if (x1 != x2 && y1 == y2) {
            ax1 = x1;
            ax2 = x2;
            if (y1 != 0) {
                ay1 = 0;
                ay2 = 0;
            }
            else {
                ay1 = n-1;
                ay2 = n-1;
            }
        } // now diff y, same x
        else if (x1 == x2 && y1 != y2) {
            ay1 = y1;
            ay2 = y2;
            if (x1 != 0) {
                ax1 = 0;
                ax2 = 0;
            } 
            else {
                ax1 = n-1;
                ax2 = n-1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == x1 && j == y1)
                    cout << '*';
                else if (i == x2 && j == y2)
                    cout << '*';
                else if (i == ax1 && j == ay1)
                    cout << '*';
                else if (i == ax2 && j == ay2)
                    cout << '*';
                else
                    cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}
