#include <bits/stdc++.h>
using namespace std;

struct obj {
    int d, s, i;
};
vector<int> arr;

bool cmp(int a, int b)
{
    return arr[a] > arr[b];
}

bool cmp2(obj a, obj b)
{
    return a.d > b.d;
}

int main()
{
    freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);

    int n, b; cin >> n >> b;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    vector<int> sortArr;
    for (int i = 1; i < n-1; i++)
        sortArr.push_back(i);
    sort(sortArr.begin(), sortArr.end(), cmp);
    // indices of all elements except first and last
    set<int> index;
    for (int i = 0; i < n; i++)
        index.insert(i);

    vector<obj> query(b);
    for (int i = 0; i < b; i++) {
        cin >> query[i].d >> query[i].s;
        query[i].i = i;
    }
    sort(query.begin(), query.end(), cmp2);
    
    vector<bool> ans(b);

    int cnt = 0, mx = 1;
    for (obj cur: query) {
        while (cnt < n && arr[sortArr[cnt]] > cur.d) {
            int x = sortArr[cnt];
            auto it = index.find(x);
            mx = max(mx, *next(it) - *prev(it));
            index.erase(it);
            cnt++;
        }
        ans[cur.i] = (cur.s >= mx);
    }

    for (bool x: ans)
        cout << x << '\n';
}