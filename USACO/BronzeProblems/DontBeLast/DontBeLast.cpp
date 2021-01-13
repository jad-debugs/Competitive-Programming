/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("notlast.in","r",stdin);
 	freopen("notlast.out","w",stdout);
	set<int> milk;
 	map<string, int> map = {
 		{"Bessie", 0},
 		{"Elsie", 0},
 		{"Daisy", 0},
 		{"Gertie", 0},
 		{"Annabelle", 0},
 		{"Maggie", 0},
 		{"Henrietta", 0},
 	};

 	int n;
 	cin >> n;

 	for(int i = 0; i < n; i++) {
 		string cow;
 		int cowNum;
 		cin >> cow;
 		cin >> cowNum;
 		map[cow]+=cowNum;
 	}

 	for(pair<string, int> x: map) {
 		milk.insert(x.second);
 	}
 	int numFound = 0;
 	set<int>::iterator it = milk.begin();
	advance(it, 1); // might return error if set small less 2
 	
 	string ans;
 	

 	for(pair<string, int> p: map) {
 		if(p.second == *it) {
 			numFound++;
 			if(numFound==1)
 				ans = p.first;
 		}
 	}

 	if(numFound==1)
 		cout << ans << "\n";
 	else
 		cout << "Tie\n";

 	return 0;
}