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

string str;
ll k, n;
bool done = false;
char ans = 'X';

void get(ll cur)
{
    // cout << cur << endl;
    if (cur <= n) {
        ans = str[(int)cur-1];
        done = true;
        return;
    }

    ll p = 1;
    

    if (!((cur/n)&(cur/n-1)) && cur%n==0) {
        while (p*2 < cur/n)
            p*=2;
    }
    else {
        while (p*2 < cur/n+1)
            p*=2; 
    }
    ll behind = n*p;

    if (cur - behind - 1 == 0)
        get(behind);
    else
        get(cur - behind - 1);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("cowcode");

    cin >> str;
    cin >> k;

    n = str.size();

    get(k);

    cout << ans;

    return 0;
}
