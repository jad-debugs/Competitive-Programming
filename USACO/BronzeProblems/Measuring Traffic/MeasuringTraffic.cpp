/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "traffic") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

	int n; cin >> n;

	int none[2] = {-1, 1001};

	string r1[n]; int r2[n], r3[n];
	
	for(int i = 0; i < n; i++) {
		cin >> r1[i] >> r2[i] >> r3[i];
		if(r1[i] == "none") {
			none[0] = max(none[0], r2[i]);
			none[1] = min(none[1], r3[i]);
		}
	}

	// before on

	int A[2] = {none[0], none[1]}; int B[2] = {none[0], none[1]}; 


	for(int i = 0; i < n; i++) {
		if(r1[i] == "on") {
			A[0] -= r3[i];
			A[1] -= r2[i];
		}
	}

	for(int i = 0; i < n; i++) {
		if(r1[i] == "off") {
			B[0] -= r3[i];
			B[1] -= r2[i];
		}
	}

	cout << A[0] << " " << A[1] << "\n" << B[0] << " " << B[1];

}
