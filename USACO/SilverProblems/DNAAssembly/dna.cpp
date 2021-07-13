#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n, ans = 1e9;
string cur;
bool visited[8];
vector<string> strings;

string merge(string a, string b)
{
    const int sz1 = a.size();
    const int sz2 = b.size();
    for (int k = 0; k < sz1; k++) {
        int i = 0, j = k;        
        while (a[j] == b[i] && j < sz1 && i < sz2) {
            i++, j++;
        }
        if (j == sz1) {
            a.replace(k, sz2, b);
            return a;
        }
    }
    return a+b;
}


void dfs(int pos)
{
    if (pos == n) {
        ans = min(ans, (int)cur.size());
        return;
    }
    string tmp = cur;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        if (cur.size() == 0)
            cur += strings[i];
        else
            cur = merge(cur, strings[i]);
        visited[i] = 1;
        dfs(pos+1);
        visited[i] = 0;
        cur = tmp;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        strings.push_back(str);
    }

    dfs(0);

    cout << ans;

    return 0;
}
