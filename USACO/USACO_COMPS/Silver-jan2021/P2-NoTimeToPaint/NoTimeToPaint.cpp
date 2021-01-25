#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, q; cin >> n >> q;

    string s; cin >> s;

    while(q--) {
        int a, b; cin >> a >> b;
        a--; b--;

        int ans = 0;
        bool stroke = false;

        for(char ch = 'A'; ch <= 'Z'; ch++) {
            stroke = false;
            for(int i = 0; i < n; i++) {
                if(s[i] < ch || a <= i && i <= b) {
                    stroke = false;
                }
                else if(s[i]==ch) {
                    if(stroke == false) {
                        ans++;
                        stroke = true;
                    }
                    else
                        continue;
                }
            }
        }
        cout << ans << "\n";
    }
}