#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int main() {
    int n, x; cin >> n >> x;
    vi a(n);
    unordered_map<int, int> vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if(vals.count(x - a[i])){
            cout << i + 1 << " " << vals[x - a[i]] << "\n";
            return 0;
        }
        vals[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << '\n';
}