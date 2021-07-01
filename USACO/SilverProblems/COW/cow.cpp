#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int main()
{
    // might work, c++ if c, co += c if o, cow += co if w
    int n; cin >> n;
    string str; cin >> str;

    ll int c = 0, co = 0, cow = 0;    

    for (char ch: str) {
        if (ch == 'C')
            c++;
        else if (ch == 'O')
            co += c;
        else if (ch == 'W')
            cow += co;
    }

    cout << cow;

    return 0;
}

/*
vector<pair<ll, ll>> cnt(n+1);
    vector<int> cPos;

    for (int i = n-1; i >= 0; i--) {
        cnt[i].f = cnt[i+1].f;
        cnt[i].s = cnt[i+1].s;


        if (str[i] == 'O')
            cnt[i].f++;
        if (str[i] == 'W') {
            cnt[i].s++;
            cnt[i].f = 0;
        }
        if (str[i] == 'C')
            cPos.push_back(i);

    }

    int szC = (int)cPos.size();

    vector<ll> ow(szC);

    for (int i = 0; i < szC; i++) {
        int x = cPos[i];
        ow[i] = cnt[x].f*cnt[x].s;
    }

    ll sf = 0;
    for (int i = 0; i < szC; i++) {
        ow[i] += sf;
        sf = ow[i];
    }


    ll ans = 0;

    for (ll x: ow) {
        ans += x;
    }
*/
