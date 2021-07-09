#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool dp[21][21][21] = {0};

int A, B, C;

void go(int a, int b, int c)
{
    int aa = a, bb = b, cc = c;

    // a -> b
    if (aa > 0 && bb < B) {
        int diff = min(aa, B - bb);
        aa -= diff;
        bb += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }

    aa = a, bb = b, cc = c;

    // a->c 
    if (aa > 0 && cc < C) {
        int diff = min(aa, C - cc);
        aa -= diff;
        cc += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }

    aa = a, bb = b, cc = c;
    // b -> a
    if (bb > 0 && aa < A) {
        int diff = min(bb, A - aa);
        bb -= diff;
        aa += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }
    aa = a, bb = b, cc = c;
    // b -> c
    if (bb > 0 && cc < C) {
        int diff = min(bb, A - aa);
        bb -= diff;
        aa += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }

    aa = a, bb = b, cc = c;
    // c -> a
    if (cc > 0 && aa < A) {
        int diff = min(cc, A - aa);
        cc -= diff;
        aa += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }

    aa = a, bb = b, cc = c;
    // c -> a
    if (cc > 0 && bb < B) {
        int diff = min(cc, B - bb);
        cc -= diff;
        bb += diff;
        if (!dp[aa][bb][cc]) {
            dp[aa][bb][cc] = 1;
            go(aa, bb, cc);
        }
    }
}

int main()
{
    cin >> A >> B >> C;

    dp[0][0][C] = 1;
    go(0, 0, C);

    set<int> set;

    for (int i = 0; i <= B; i++) {
        for (int j = 0; j <= C; j++) {
            if (dp[0][i][j])
                set.insert(j);
        }
    }

    for (int x: set)
        cout << x << ' ';

    return 0;
}
