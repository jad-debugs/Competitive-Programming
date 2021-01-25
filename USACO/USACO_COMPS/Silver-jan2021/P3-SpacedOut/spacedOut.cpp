#include <bits/stdc++.h>
using namespace std;

int n;
const int hi = 21;
static int max_beaut = -1;

bool works2_2(char f[][hi], int n)
{
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            int a, b, c = 0;

            for(int a = 0; a < 2; a++) {
                for(int b = 0; b < 2; b++) {
                    if(f[i+a][j+b] == 'C')
                        c++;
                }
            }
            if(c != 2) return false;
        }
    }
    return true;
} 

void countBeaut(int b[][hi], char f[][hi], int n)
{
    int i, j, cur = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(f[i][j] == 'C')
                cur += b[i][j];
        }
    }
    if(cur > max_beaut) max_beaut = cur;
}

void capBeaut(int b[][hi], char f[][hi], int n, int i, int j)
{
    if(j == n) {
        i++; j = 0;
    }

    if(i == n) {
        if(works2_2(f, n) == false) return;
        countBeaut(b, f, n); return;
    }

    f[i][j] = '.';
    capBeaut(b, f, n, i, j+1);
    f[i][j] = 'C';
    capBeaut(b, f, n, i, j+1);
}

int main()
{
    int n; cin >> n;

    char board[n][hi];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    int beuaty[n][hi];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> beuaty[i][j];
    }
    capBeaut(beuaty, board, n, 0, 0);
    cout << max_beaut << "\n";
}