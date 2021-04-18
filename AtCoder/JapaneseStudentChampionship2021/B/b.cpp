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
}


int main()
{
    setIO("");

    int a, b; cin >> a >> b;

    bool Aarr[1005] = {0};
    bool Barr[1005] = {0};

    for (int i = 0; i < a; i++) {
        int tmp; cin >> tmp;
        Aarr[tmp] = 1;
    }

    for (int i = 0; i < b; i++) {
        int tmp; cin >> tmp;
        Barr[tmp] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < 1005; i++) {
        if ((Aarr[i] && !Barr[i]) || (!Aarr[i] && Barr[i])) {
            if (cnt == 0)
                cout << i;
            else
                cout << ' ' << i;
            cnt++;
        }
    }
    cout << '\n';
    return 0;
}
