/*ID: jadDebugs
TASK: ride
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <string>
#include <stdio.h>
using namespace std;
int main () {
	freopen("ride.in","r",stdin);
 	freopen("ride.out","w",stdout);
	int sumUFO = 1;
	int sumGroup = 1;
	string UFO;
	string group;
    getline (cin, UFO);
    getline (cin, group);
    for(int i = 0; i<UFO.length();i++){
    	sumUFO *= (int)(UFO[i])-64;
    }
    for(int j = 0; j<group.length();j++){
    	sumGroup *= (int)(group[j])-64;
    }
    if(sumGroup%47==sumUFO%47){
    	cout << "GO" << "\n";
    }
    else {
    	cout << "STAY" << "\n";
    }
    return 0;
}