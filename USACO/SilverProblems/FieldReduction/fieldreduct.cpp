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

bool cmp(pii a, pii b)
{
    return a.s < b.s;
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
    setIO("reduce");
    int n; cin >> n;

    vector<pii> points1(n);

    for (int i = 0; i < n; i++)
        cin >> points1[i].f >> points1[i].s;

    vector<pii> points2 = points1;

    sort(points1.begin(), points1.end());
    sort(points2.begin(), points2.end(), cmp);

    int ans = 2e9;

    for (int i = 0; i < 4; i++) {
        for (int j = n-1; j > n - 5; j--) {
            for (int a = 0; a < 4; a++) {
                for (int b = n-1; b > n-5; b--) {
                    // checking for reused deleted points

                    int deleted = i + a + (n - 1 - j) + (n - 1 - b);

                    for (int g = 0; g < i; g++) {
                        for (int c = 0; c < a; c++) {
                            if (points1[g] == points2[c])
                                deleted--;
                        }
                        for (int c = b+1; c < n; c++) {
                            if (points1[g] == points2[c])
                                deleted--;
                        }
                    }
                    
                    for (int g = j+1; g < n; g++) {
                        for (int c = 0; c < a; c++) {
                            if (points1[g] == points2[c])
                                deleted--;
                        }
                        for (int c = b+1; c < n; c++) {
                            if (points1[g] == points2[c])
                                deleted--;
                        }
                    }

                    if (deleted > 3 || deleted < 0)
                        break;

                    // cout << points1[i].f << ' ' << points1[j].f << ' ' << points2[a].s << ' ' << points2[b].s << endl;
                    int area = (points1[j].f - points1[i].f)*(points2[b].s - points2[a].s);

                    if (area < 0)
                        area = 2e9;

                    ans = min(ans, area);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
