/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <iostream> // bits/stdc++.h
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main () {
	freopen("blocks.in","r",stdin);
 	freopen("blocks.out","w",stdout);
 	
 	int n;
 	cin >> n;

 	string words[n][2];
 	int alphabet[26];

 	for(int i = 0; i < 26; i++){
 		alphabet[i] = 0;
 	}

 	for(int i = 0; i < n; i++){
 		cin >> words[i][0] >> words[i][1];
 	}

 	for(int a = 0; a < n; a++){
 		for(char b = 'a'; b <= 'z'; b++){
 			int tmp1 = 0;
 			int tmp2 = 0;

 			for(int c = 0; c < words[a][0].length();c++){
 				if((words[a][0])[c] == b){
 					tmp1++;
 				}
 			}

 			for(int c = 0; c < words[a][1].length();c++){
 				if((words[a][1])[c] == b){
 					tmp2++;
 				}	
 			}
 			alphabet[122-b] += max(tmp1,tmp2);
 		}
 	}
 	for(int res = 25; res >= 0; res--){
 		cout << alphabet[res]  << endl;
 	}

 	return 0;
}