#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct mountain {
    int x, y;
};

bool cmpM(mountain one, mountain two)
{
    if(one.x - one.y == two.x - two.y)
       return one.x + one.y > two.x + two.y;
    return one.x - one.y < two.x - two.y;

}

int main()
{
    setIO("mountains");
    int n; cin >> n;

    mountain arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr+n, cmpM);

    int right = 0, ans = 0;

    for(auto mv: arr) {
        if(mv.x + mv.y > right) {
            ans++;
            right = mv.x + mv.y;
        }
    }
    cout << ans;
}
