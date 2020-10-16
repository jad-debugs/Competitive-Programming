/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h> // bits/stdc++.h
#include <stdio.h>
using namespace std;

int main () {
	//freopen("billboard.in","r",stdin);
 	//freopen("billboard.out","w",stdout);
 	
 	int ax1, ax2, ay1, ay2;
 	int bx1, bx2, by1, by2;

 	cin >> ax1 >> ay1 >> ax2 >> ay2;
 	cin >> bx1 >> by1 >> bx2 >> by2;

 	int area1 = (bx2-bx1)*(by2-by1);
 	int area = (ax2-ax1)*(ay2-ay1);


 	int intersectionX = max(0, min(ax2, bx2) - max(ax1, bx1));
 	int intersectionY = max(0, min(by2, ay2) - max(by1, ay1));

 	int res = area - intersectionX*intersectionY;

 	bool flag = false;
 	for(int i = 2; i < res; i++){
 		if(res%i==0)
 			flag = true;
 	}

 	if(area1 > area)
 		cout << 0;
 	else
 	cout << (flag ? res : area);

 	return 0;
}
/* 
2 1 7 4
5 -1 10 3
*/