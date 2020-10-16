/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

int main () {
	freopen("square.in","r",stdin);
 	freopen("square.out","w",stdout);
 	
	int ax1, ay1, ax2, ay2;
	int bx1, by1, bx2, by2;
	cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

	int maxX = max(ax2, bx2);
	int minX = min(ax1, bx1);
	
	int maxY = max(ay2, by2);
	int minY = min(ay1, by1);

	int side = max(maxY-minY, maxX-minX);

	cout << side*side;

 	return 0;
}
/*
6 6 8 8
1 8 4 9
*/