#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    string str; cin >> str;
    unordered_set<char> distinct;

    for (int i = 0; i < n; i++)
        distinct.insert(str[i]);

    const int sz = distinct.size();
    map<char, int> map;

    int l = 0, r = 0, ans = 1e9;
    for (; l < n; l++) {
        while (r < n && (int)map.size() < sz)
            map[str[r++]]++;
        if ((int)map.size() == sz)
            ans = min(r - l, ans);
        map[str[l]]--;
        if (map[str[l]] == 0)
            map.erase(str[l]);
        
    }
    cout << ans;
}
