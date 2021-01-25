#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    int f[k], s[k];

    for(int i = 0; i < k; i++) {
        cin >> f[i] >> s[i];
    }

    int org[n];

    for(int i = 0; i < n; i++) {
        org[i] = i+1;
    }

    unordered_set<int> pos[n+1];

    for(int j = 0; j < n; j++) {
        pos[j+1].insert(j);
    }

    for(int dances = 0; dances < 500; dances++) {
        for(int i = 0; i < k; i++) {
            pos[org[f[i]-1]].insert(s[i]-1);
            pos[org[s[i]-1]].insert(f[i]-1);
            // swap
            int a = org[f[i]-1];
            int b = org[s[i]-1];
            org[f[i]-1] = b;
            org[s[i]-1] = a;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << pos[i].size() << "\n";
    }
}