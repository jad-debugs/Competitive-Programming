#include <bits/stdc++.h>
using namespace std;

char solve(string bits, string alphabet) {
    if(bits.size() <= 1) return (alphabet[(int)bits[0] - '0']); 
    
    if(bits[0] == '0') return solve(bits.substr(1), alphabet.substr(0, alphabet.size()/2));
    else return solve(bits.substr(1), alphabet.substr(alphabet.size()/2, alphabet.size()/2));
}

int main()
{
    int t; cin >> t;

    string ans[t];

    for(int i = 0; i < t; i++) {
		ans[i] = "";
        int n; cin >> n;
        string bits; cin >> bits;
        for(int j = 0; j < n/4; j++) {
            ans[i] += solve(bits.substr(j*4, 4), "abcdefghijklmnop");
        }
    }
    for(int i = 0; i < t-1; i++)
        cout << ans[i] << "\n";
    cout << ans[t-1];
    return 0;
}
