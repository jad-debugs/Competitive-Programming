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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    
}


int main()
{
    setIO("");

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;
        ll arr[k];
        for(int i = 0; i < k; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++) {
            string bin; cin >> bin;
            ll score = 0;
            for(int i = 0; i < (int)bin.size(); i++) {
                if(bin[i] == '1')
                    score += arr[i];
            }
            cout << score << "\n";
        }
    }

    return 0;
}
