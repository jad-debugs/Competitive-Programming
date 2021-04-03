#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, sz; cin >> n >> sz;
    int lanterns[n];

    for (int i = 0; i < n; i++)
        cin >> lanterns[i];

    long double maxDiff = 0.0;
    
    sort(lanterns, lanterns + n);

    maxDiff = fmax(maxDiff, lanterns[0] - 0);
    maxDiff = fmax(maxDiff, sz - lanterns[n-1]);

    for (int i = 1; i < n; i++) {
        if ((lanterns[i] - lanterns[i-1])/(float)2.0 > maxDiff)
            maxDiff = (lanterns[i] - lanterns[i-1])/(float)2.0;
    }
    cout << setprecision(15) << fixed << maxDiff;
}
/*
7 15
15 5 3 7 9 14 0
*/
