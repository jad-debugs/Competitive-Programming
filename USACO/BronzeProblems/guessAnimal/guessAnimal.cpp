/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "guess") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO();

    int n;
    cin >> n;
    vector<vector<string>> traits;
    for(int i = 0; i < n; i++) {
    	string word; cin >> word;
    	int t; cin >> t;
    	vector<string> tmpV(t);
    	for(int j = 0; j < t; j++) {
    		cin >> tmpV[j];
    	}
    	traits.push_back(tmpV);
    }
    int ans = 0;
    for(int i = 0; i < traits.size()-1; i++) {
    	for(int j = i+1; j < traits.size(); j++) {
    		int tmp;
    		set<string> common;
    		for(int a = 0; a < traits[i].size(); a++) {
    			common.insert(traits[i][a]);
    		}
    		for(int b = 0; b < traits[j].size(); b++) {
    			common.insert(traits[j][b]);
    		}
    		tmp = traits[i].size()+traits[j].size()-common.size()+1;
    		ans = max(ans, tmp);
    		common.clear();
    	}
    }
    cout << ans;
}
