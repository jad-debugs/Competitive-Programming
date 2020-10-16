/*ID: jadDebugs
TASK: -----
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

struct Rect {
	int x1, x2, y1, y2;
	int area()
	{
		return (x2 - x1)*(y2-y1);
	}
};

int intersection(Rect x, Rect y)
{
	int xOverlax = max(0,min(x.x2,y.x2)-max(x.x1,y.x1));
    int yOverlax = max(0,min(x.y2,y.y2)-max(x.y1,y.y1));
    return xOverlap*yOverlap;
}

int main(){
	//freopen("billboard.in","r",stdin);
 	//freopen("billboard.out","w",stdout);

    Rect a, b, c;
 	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >>c.x2 >> c.y2;
 	

}
