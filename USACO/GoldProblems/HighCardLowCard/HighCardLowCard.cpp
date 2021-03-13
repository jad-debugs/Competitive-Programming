#include <iostream> // using clang compiler rn and dont wanna precompile entire std
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n; cin >> n;

    map<int, bool> lS;
    vector<int> lose;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        lS[a] = true;
        lose.push_back(a);
    }

    sort(lose.begin(), lose.begin() + n/2);

    vector<int> win;

    for (int i = 2*n; i >= 1; i--) {
        if (lS[i] == 0)
            win.push_back(i);
    }
    
    sort(win.begin(), win.begin() + n/2);

    int ptr1 = 0, ptr2 = 0, ans = 0;
    while (ptr1 != n/2 && ptr2 != n/2) {
        if (win[ptr1] > lose[ptr2]) {
            ans++;
            ptr1++;
            ptr2++;
        }
        else
            ptr1++;
    }

    sort(lose.begin()+n/2, lose.end());
    sort(win.begin()+n/2, win.end());
    ptr1 = n/2, ptr2 = n/2;

    while (ptr1 != n && ptr2 != n) {
        if (win[ptr1] < lose[ptr2]) {
            ans++;
            ptr1++;
            ptr2++;

        }
        else
            ptr2++;
    }
    cout << ans << "\n";
}

