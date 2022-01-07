#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> v;

    DSU(int N)
    {
        v = vector<int>(N, -1);
    }

    int get(int x)
    {
        if (v[x] < 0)
            return x;
        // keep going to next leader and change current leader
        // until we get to a leader that leads to no one else
        // then we return what index he is and set us to his index
        // leading us to him as the leader, so path compression
        return v[x] = get(v[x]);
    }

    bool same(int a, int b)
    {
        return get(a) == get(b);
    }

    int size(int x)
    {
        // find the final leader of this group and return its size
        // we negate because final leaders are always negative
        return -v[get(x)];
    }

    bool unite(int a, int b)
    {
        // set to leaders of each group
        a = get(a); b = get(b);

        // alredy united
        if (a == b)
            return false;
        // we want to set smaller group onto the larger group
        // because the larger group has more nodes that already
        // lead to leader, so we have to change less later
        if (-v[a] < -v[b])
            swap(a, b);
        // new size of group
        v[a] += v[b];
        v[b] = a;
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int cc = n, mx = 1;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (dsu.unite(a, b)) {
            cout << --cc << ' ';
            mx = max(mx, max(dsu.size(a), dsu.size(b)));
            cout << mx;
        }
        else {
            cout << cc << mx;
        }
    }

    return 0;
}