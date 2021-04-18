// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int getMaxGCD(vector<int> arr, int n) {
    int high = 0;

    for (int i = 0; i < n; i++)
        high = max(high, arr[i]);

    int divisors[high + 1] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 1; j*j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                divisors[j]++;
            if (j != arr[i] / j)
                divisors[arr[i] / j]++;
            }
        }
    }

        for (int i = high; i >= 1; i--) {
            if (divisors[i] > 1)
                return i;
        }
    return -1;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    int a, b; cin >> a >> b;
    vector<int> arr(b-a+1);

    for (int i = a; i <= b; i++)
        arr[i-a] = i;

    cout << getMaxGCD(arr, b-a+1);
    return 0;
}
