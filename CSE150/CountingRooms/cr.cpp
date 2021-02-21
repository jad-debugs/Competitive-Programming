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

int n, m;

char arr[2500][2500];
bool visited[2500][2500];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

void floodfill(int i, int j)
{
    if(visited[i][j] || arr[i][j] == '#' || i < 0 || i >= n || j < 0 || j >= m) return;
    visited[i][j] = 1;
    floodfill(i+1, j);
    floodfill(i-1, j);
    floodfill(i, j+1);
    floodfill(i, j-1);
}

int main()
{
    setIO();

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && arr[i][j] == '.') {
                floodfill(i, j);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
