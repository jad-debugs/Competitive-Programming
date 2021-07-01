#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main()
{
    int n, a, b; cin >> n >> a >> b;

    vector<pair<int, bool>> cows(n, {0, false});

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        if (str == "S")
            cows[i].s = 1;
        else
            cows[i].s = 0;
        cin >> cows[i].f;
        cows[i].f *= 2;
    }

    sort(cows.begin(), cows.end());

    int ans = 0;

    for (int i = a; i <= b; i++) {
        auto frP = upper_bound(cows.begin(), cows.end(), make_pair(i*2, false));
        vector<pair<int, bool>>::iterator brP;

        if (frP == cows.begin())
            brP = cows.end();
        else
            brP = prev(frP);

        if (brP == cows.end()) {
            if (frP->s)
                ans++;
        }
        else if (frP == cows.end()) {
            if (brP->s) {
                ans++;
            }
        }
        else {
            int mid = (frP->f + brP->f)/2;
            if (i*2 > mid)
                ans += (frP->s ? 1: 0);
            else if (i*2 < mid)
                ans += (brP->s ? 1: 0);
            else if (frP->s || brP->s) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}