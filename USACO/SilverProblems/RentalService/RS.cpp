#include <bits/stdc++.h>
using namespace std;

struct sellMilk {
    int cowsOpen, price;
};

bool cmpInt(int a, int b) {
    return a > b;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    int cows[n], prices[n] = {0};
    vector<int> milkSales;

    for(int i = 0; i < n; i++)
        cin >> cows[i];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        milkSales.resize(b, a); 
    }

    for(int i = 0; i < r; i++)
        cin >> prices[i];

    sort(cows, cows+n);
    sort(milkSales.begin(), milkSales.end(), cmpInt);
    sort(prices, prices + r, cmpInt);

    int ans = 0;

    int curPlace = 0;
    for(int i = n-1; i >= 0; i--) {
        int milkSell = 0;
        int org = curPlace;
        for(int j = curPlace; j < org + cows[i]; j++) {
            curPlace = j;
            milkSell += milkSales[j];
        }
        ans += max(prices[i], milkSell);
    }
    cout << ans;
    return 0;
}
