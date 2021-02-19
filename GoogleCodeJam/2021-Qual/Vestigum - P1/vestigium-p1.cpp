// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}


int main()
{
    setIO();

    int t; cin >> t;

    for(int z = 1; z <= t; z++) {
        int n; cin >> n;
        cout << "case #" << z << ": ";

        int matrix[n][n];

        int trace = 0;

        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                cin >> matrix[a][b];
                if(a == b)
                    trace += matrix[a][b];
            }
        }
        cout << trace << " ";

        int row = 0;

        for(int i = 0; i < n; i++) {
            set<int> rowS;
            for(int j = 0; j < n; j++) {
                if(rowS.count(matrix[i][j])) {
                    row++;
                    break;
                }
                else
                    rowS.insert(matrix[i][j]);
            }
        }
        cout << row << " ";

        int col = 0;

        for(int i = 0; i < n; i++) {
            set<int> colS;
            for(int j = 0; j < n; j++) {
                if(colS.count(matrix[j][i])) {
                    col++;
                    break;
                }
                else
                    colS.insert(matrix[j][i]);
            }
        }
        cout << col << "\n";
    }

    return 0;
}
