#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    vector<long long> left(5005);
    vector<long long> right(5005);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        left[a]++;
        right[b]++;
    }

    vector<long long> pfl(1e6);
    vector<long long> pfr(1e6);

    for (int i = 0; i < 5004; i++) {
        for (int j = 0; j <= 5004; j++) {
            pfl[i+j] += left[i]*left[j];
            pfr[i+j] += right[i]*right[j];
        }
    }

    long long ans = 0;

    for (int i = 0; i <= 2*m; i++) {
        ans += pfl[i];
        cout << ans << '\n';
        ans -= pfr[i];
    }
    
}