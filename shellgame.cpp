/*ID: jadDebugs
TASK: USACO 2019 January Contest, Bronze
Problem 1. Shell Game
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <stdio.h>
using namespace std;

int main () {
	freopen("shell.in","r",stdin);
 	freopen("shell.out","w",stdout);
 	
 	int n;
 	int counter = 0;
 	int result = 0;
 	cin >> n;
 	int a[n];
 	int b[n];
 	int g[n];

 	for(int j = 0; j < n; j++){
 		cin >> a[j] >> b[j] >> g[j];
 	}

 	for(int i = 1; i <= 3; i++){
 		int location = i;
 		counter = 0;
 		for(int j = 0; j<n; j++){
 			if(a[j] == location){
 				location = b[j];
 			}
 			else if(b[j] == location){
 				location = a[j];
 				}
 		
 		if(location == g[j]){
 			counter++;
 			}
 		}
 		result = max(result,counter);
 	}
 	cout << result;
 	return 0;
}