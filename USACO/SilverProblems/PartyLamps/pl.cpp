#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n, c;

set<vector<int>> s;
vector<int> currentState(105, 1);
vector<int> finalState(105, -1);

void go(int num)
{
    if (num >= c) {
        bool works = true;
        for (int i = 1; i <= n; i++) {
            if (finalState[i] == -1)
                continue;
            if (currentState[i] != finalState[i]) {
                works = false;
                break;
            }
        }
        if (works)
            s.insert(currentState);
        return;
    }
    for (int i = 1; i <= n; i++) {
        currentState[i] ^= 1;
    }
    go(num+1);
    for (int i = 1; i <= n; i+=2) {
        currentState[i] ^= 1;
    }
    go(num+1);
    for (int i = 2; i <= n; i+=2) {
        currentState[i] ^= 1;
    }
    go(num+1);
    for (int i = 1; i <= n; i+=3) {
        currentState[i] ^= 1;
    }
    go(num+1);
}

int main()
{
    cin >> n >> c;
    c = min(c, 4);


    int x;
    while (cin >> x) {
        if (x==-1)
            break;
        finalState[x] = 1;
    }
    while (cin >> x) {
        if (x == -1)
            break;
        finalState[x] = 0;
    }

    go(0);

    if (s.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (vector<int> v: s) {
        for (int i = 1; i <= n; i++)
            cout << v[i];
        cout << "\n";
    }

    return 0;
}
