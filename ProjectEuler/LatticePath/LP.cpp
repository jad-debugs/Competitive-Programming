#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long ans = 1;
    bool visited[21] = {0};
    vector<int> divisors;
    for (int i = 2; i <= 20; i++)
        divisors.push_back(i);
    for (int i = 21; i <= 40; i++) {
        for (int j = 2; j <= 20; j++) {
            if (!visited[j] && ans%i == 0) {
                visited[j] = true;
                ans /= j;
            }
        }
        ans *= i;
    }
    for (int i = 2; i <= 20; i++) {
        if (!visited[i])
            ans /= i; 
    }
    cout << ans;
    return 0;
}
