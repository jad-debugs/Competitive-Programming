#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int board[10][10];
bool done = 0;

bool check(int r, int c)
{
    set<int> set;

    for (int i = 0; i < 9; i++) {
        if (set.find(board[r][i]) != set.end()) {
            return false;
        }
        set.insert(board[r][i]);
    }

    set.clear();

    for (int i = 0; i < 9; i++) {
        if (set.find(board[i][c]) != set.end()) {
            return false;
        }
        set.insert(board[i][c]);
    }

    set.clear();
    // just check top left to our position
    int startr = r - r%3, startc = c - c%3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = board[i+startr][j+startc];
            if (set.find(cur) != set.end())
                return false;
            set.insert(cur);
        }
    }
    return true;
}

void go(int pos)
{
    if (done)
        return;
    if (pos >= 81) {
        done = 1;
        return;
    }

    int r = pos/9;
    int c = pos%9;

    if (board[r][c] != 0) {
        if (check(r, c))
            go(pos+1);
        else
            return;
    }

    if (board[r][c] == 0) {
        for (char i = 1; i <= 9; i++) {
            board[r][c] = i;
            if (check(r, c)) {
                go(pos+1);
            }
            board[r][c] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    go(0);

    if (done) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
                if (j == 8)
                    cout << '\n';
                else
                    cout << ' ';
            }
        }
    }
    

    if (!done) {
        cout << "NO SOLUTION\n";
    }

    return 0;
}
