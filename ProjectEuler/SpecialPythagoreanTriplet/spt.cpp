#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    for (int i = 1; i <= 998; i++) {
        for (int j = i+1; j <= 998; j++) {
            int c = 1000 - i - j;
            if (c == i || c == j)
                continue;
            if (i+j+c == 1000) {
                int small = min(i, min(j, c));
                int big = max(i, max(j, c));
                int mid;
                if (i != small && i != big)
                    mid = i;
                else if (j != small && j != big)
                    mid = j;
                else
                    mid = c;
                if (small*small + mid*mid == big*big) {
                    cout << i*j*c;
                    return 0;
                }
            }
        }
    }
    return 0;
}
