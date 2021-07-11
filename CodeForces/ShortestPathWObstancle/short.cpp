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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO();

    int t; cin >> t;

    while (t--) {
        int sx, sy, ex, ey, fx, fy;
        cin >> sx >> sy >> ex >> ey >> fx >> fy;

        int ans = abs(ex-sx)+abs(ey-sy);

        if (sx == fx && ex == fx) {
            int mny = min(sy, ey);
            int mxy = max(sy, ey);
            if (fy > mny && fy < mxy)
                ans+=2;
        }
        else if (sy == fy && ey == fy) {
            int mnx = min(sx, ex);
            int mxx = max(sx, ex);
            if (fx > mnx && fx < mxx)
                ans+=2;
        }
        cout << ans << '\n';
    }

    return 0;
}



/*
int startx, starty, endx, endy, fx, fy;
        cin >> startx >> starty >> endx >> endy >> fx >> fy;

        int lenx = max(startx, endx);
        int leny = max(starty, endy);

        queue<pii> q;
        bool visited[lenx][leny] = {0};
        int sol[lenx][leny] = {0};
        q.push({startx, starty});

        while (!q.empty()) {
            int r = q.front().f;
            int c = q.front().s;
            visited[r][c] = 1;
            q.pop();
            bool done = false;

            for (int i = 0; i < 4; i++) {
                int r2 = r+dx[i];
                int c2 = c+dy[i];
                if (r2 < 0 || r2 >= lenx || c2 < 0 || c2 >= leny || visited[r2][c2] || (r2 == fx && c2 == fy))
                    continue;
                visited[r2][c2] = 1;
                sol[r2][c2] = sol[r][c]+1;
                if (r2 == endx && c2 == endy) {
                    cout << sol[r2][c2] << '\n';
                    done = true;
                    break;
                }
                q.push({r2, c2});
            }
            if (done) {
                break;
            }
        }
        */
        