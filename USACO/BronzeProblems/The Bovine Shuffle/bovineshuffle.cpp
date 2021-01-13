/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <stdio.h>
using namespace std;

int main () {
	//freopen("shuffle.in","r",stdin);
 	//freopen("shuffle.out","w",stdout);
 	
 	int n;
 	cin >> n;

 	int res[n];
 	int order[n];
 	int ID[n];
    int copy[n];
    int final[n];

 	for(int i = 0; i < n; i++){
 		cin >> order[i];
 	}

 	for(int i = 0; i < n; i++){
 		cin >> ID[i];
 	}

 	for(int i = 0; i < n; i++){
        copy[i] = res[i];
    }


    for(int j = 0; j < n; j++){
        int tmp = order[j];
        tmp -= 1;
        res[tmp] = j;
    }
    for(int j = 0; j < n; j++){
        final[res[res[res[j]]]] = ID[j];
    }


    for(int i: final){
        cout << i << endl;
    }

 	return 0;
}