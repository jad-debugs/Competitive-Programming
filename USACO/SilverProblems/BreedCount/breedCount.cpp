#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    int n, q; cin >> n >> q;

    vector<int> H(n+1);
    vector<int> G(n+1);
    vector<int> J(n+1);

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a == 1) {
            H[i] = H[i-1] + 1;
            G[i] = G[i-1];
            J[i] = J[i-1];
        }
        if (a == 2) {
            H[i] = H[i-1];
            G[i] = G[i-1] + 1;
            J[i] = J[i-1];
        }
        if (a == 3) {
            H[i] = H[i-1];
            G[i] = G[i-1];
            J[i] = J[i-1] + 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << H[b] - H[a-1] << ' ' << G[b] - G[a-1] << ' ' << J[b] - J[a-1] << '\n';
    }

    return 0;
}
