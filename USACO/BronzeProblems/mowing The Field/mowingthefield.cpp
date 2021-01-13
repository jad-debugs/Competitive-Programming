/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "mowing") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

    int n; cin >> n;

    int grid[1001][1001] = {0};

    int time = 0;

    int lr = 500, ud = 500;

    int ans = 1002;

    for(int i = 0; i < n; i++) {
    	char dir; cin >> dir; int vec; cin >> vec;
    	for(int j = 1; j <= vec; j++) {
    		time++;
    		if(dir == 'N') {
    			if(grid[ud][lr] != 0)
    				ans = min(time - grid[ud][lr], ans);

    			grid[ud][lr] = time;
    			ud--;
    		}
    		else if(dir == 'S') {
    			if(grid[ud][lr] != 0)
    				ans = min(time - grid[ud][lr], ans);
    			grid[ud][lr] = time;
    			ud++;
    		}
    		else if(dir == 'W') {
    			if(grid[ud][lr] != 0)
    				ans = min(time - grid[ud][lr], ans);
    			grid[ud][lr] = time;
    			lr--;
    		}
    		else if(dir == 'E') {
    			if(grid[ud][lr] != 0)
    				ans = min(time - grid[ud][lr], ans);
    			grid[ud][lr] = time;
    			lr++;
    		}
    	}
    }

    if(ans == 1002)
    	cout << -1;
    else
    	cout << ans;
    return 0;
}
