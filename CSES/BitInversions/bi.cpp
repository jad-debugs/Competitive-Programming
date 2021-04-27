#include <bits/stdc++.h>
using namespace std;

string bits;
multiset<int> altDiff;
map<int, int> subL;

void solve(int x)
{
    const int sz = bits.size();
    if (x == 0 || x == sz)
        return;
    // store elemenet before and after
    auto tmp = altDiff.lower_bound(x); tmp--;
    int a = *tmp;
    int b = *altDiff.upper_bound(x);

    if (altDiff.count(x)) {
        subL[x-a]--;
        subL[b-x]--;
        if (subL[x-a] == 0)
            subL.erase(x-a);
        if (subL[b-x] == 0)
            subL.erase(b-x);
        altDiff.erase(x); // only one x, so no need to find
        subL[b-a]++;
    }
    else {
        subL[b-a]--;
        if (subL[b-a] == 0)
            subL.erase(b-a);
        altDiff.insert(x);
        subL[x-a]++;
        subL[b-x]++;
    }
}

int main()
{
    cin >> bits;
    const int sz = bits.size();
    
    altDiff.insert(0);
    altDiff.insert(sz);
    
    int past = 0;
    for (int i = 1; i < (int)bits.size(); i++) {
        if (bits[i] != bits[past]) {
            altDiff.insert(i);
            subL[i-past]++;
            past = i;
        }
    }
    
    subL[sz-past]++;

    int n; cin >> n;
    vector<int> changes(n);

    for (int i = 0; i < n; i++)
        cin >> changes[i];
    int cnt = 0;
    for (int x: changes) {
        solve(x-1);
        solve(x);
        cout << subL.rbegin()->first;
        if (cnt != n-1)
            cout << ' ';
        cnt++;
    }
    return 0;
}
