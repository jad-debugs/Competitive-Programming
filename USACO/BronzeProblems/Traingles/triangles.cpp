/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

int main () {
	freopen("triangles.in","r",stdin);
 	freopen("triangles.out","w",stdout);
 	int n;
 	cin >> n;
 	int X[n];
 	int Y[n];
 	int area = 0;

 	for(int i = 0; i < n; i++){
 		cin >> X[i] >> Y[i];
 	}
 	
 	for(int a = 0; a < n; a++){
 		for(int b = 0; b < n; b++){
 			for(int c = 0; c < n; c++){
 				if(X[a] == X[b]){
 					if(Y[b] == Y[c]){
 						int tmp = (Y[c]-Y[a])*(X[c]-X[a]);
 						area = max(area, abs(tmp));
 					}
 				}
 			}
 		}
 	}
 	cout << area;
 	return 0;
}