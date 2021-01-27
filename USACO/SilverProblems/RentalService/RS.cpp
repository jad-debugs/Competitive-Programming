#include <bits/stdc++.h>
using namespace std;

struct sellMilk {
    long long f, s;
};

bool cmpInt(int a, int b)
{
    return a > b;
}

bool cmpSM(sellMilk a, sellMilk b)
{
    if(a.s == b.s) return a.f > b.f;
    return a.s > b.s;
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
    setIO("rental");
    long long n, m, r;
    cin >> n >> m >> r;

    long long cows[n], prices[r];
    sellMilk milkSales[m];

    for(long long i = 0; i < n; i++)
        cin >> cows[i];

    for(long long i = 0; i < m; i++) {
        long long a, b; cin >> a >> b;
        milkSales[i] = {a, b};
    }

    for(long long i = 0; i < r; i++)
        cin >> prices[i];

    sort(cows, cows + n, cmpInt);
    sort(prices, prices + r, cmpInt);
    sort(milkSales, milkSales + m, cmpSM);


    long long curmilk = 0;
    long long ans = 0;
    for(long long a = 0; a < n; a++) {
        long long cow = cows[a];
        long long mc = 0, sc = 0;
        // sell
        while(true) {
            long long f = milkSales[curmilk].f;
            long long s = milkSales[curmilk].s;
            if (cow < f) {milkSales[curmilk].f -= cow; mc += cow*s; break;}

            else if (cow > f) {
                cow -= f;
                curmilk++;
                mc += f*s;
            }
            else if (cow == f) {curmilk++; mc += f*s; break;}
        }
        // price
        if(n-a < r) {sc = prices[n-a-1];}

        bool done = false;

        if(sc >= mc) {
            done = true;
            for(long long b = 0; b <= n-a-1; b++) ans += prices[b];
            break;
        }
        if(!done) ans += mc;
    }
    cout << ans; 
    return 0;
}
