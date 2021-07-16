#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n, s, e, ans = 0, ex[20][9] = {0}, cnt[9] = {0};

bool check()
{
    for (int i = 0; i < e; i++) {
        bool works = true;
        for (int j = 1; j <= s; j++) {
            if (cnt[j] < ex[i][j]) {
                works = false;
                break;
            }
        }
        if (works)
            return true;
    }
    return false;
}

void go(int num)
{
    if (num > n) {
        if (check())
            ans++;
        return;
    }
    for (int i = 1; i <= s; i++) {
        cnt[i]++;
        go(num+1);
        cnt[i]--;
    }
}

int main()
{
    cin >> n >> s >> e;

    for (int i = 0; i < e; i++) {
        string str; cin >> str;
        for (int j = 0; j < (int)str.size(); j+=4) {
            int a = str[j]-'0';
            int b = str[j+2]-'0';
            ex[i][b] = a;
        }
    }

    go(1);
    cout << ans;

    return 0;
}
