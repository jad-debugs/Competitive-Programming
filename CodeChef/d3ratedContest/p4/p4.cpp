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

vector<bool> graph[1001];
bool visited[1001][1001];

int u = 0;
int d = 0;
int l = 0;
int r = 0;

void ff(int i, int j, int n, int m)
{
    if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || !graph[i][j])
        return;
    visited[i][j] = true;
    ff(i+1, j, n, m);
    d++;
    ff(i-1, j, n, m);
    u++;
    ff(i, j+1, n, m);
    r++;
    ff(i, j-1, n, m);
    l++;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
   //setIO("");
   
    int t; cin >> t;

    while(t--) {
        
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool a; cin >> a;
                graph[i].push_back(a);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && graph[i][j]) {
                    ff(i, j, n, m);
                    break;
                }
            }
        }
        cout << "HEYA";
        cout << u << " " << l << "\n";
    }

    return 0;
}
