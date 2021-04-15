#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll arr[20][20] = {0};

ll ff(int x, int y)
{
    ll ans = 0;
    if (x + 3 < 20)
        ans = max(ans, arr[x][y]*arr[x+1][y]*arr[x+2][y]*arr[x+3][y]);
    if (y + 3 < 20)
        ans = max(ans, arr[x][y]*arr[x][y+1]*arr[x][y+2]*arr[x][y+3]);
    if (x + 3 < 20 && y + 3 < 20) 
        ans = max(ans, arr[x][y]*arr[x+1][y+1]*arr[x+2][y+2]*arr[x+3][y+3]);
    if (x + 3 < 20 && y - 3 >= 0)
        ans = max(ans, arr[x][y]*arr[x+1][y-1]*arr[x+2][y-2]*arr[x+3][y-3]);
    return ans;
}

int main()
{
    // input so we dont have to format
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> arr[i][j]; 
        }
    }
    ll ans = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            ans = max(ans, ff(i, j));
        }
    } 
    cout << ans;
    return 0;
}
