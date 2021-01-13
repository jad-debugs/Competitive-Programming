#include <bits/stdc++.h>
using namespace std;

int main()
{
	int d1, d2, v1, v2, goal; cin >> d1 >> v1 >> d2 >> v2 >> goal;

	int curDay = 0;
	int total = 0;

	while(goal > total) {
		
		curDay++;

		if(d1 <= curDay) {
			total += v1;
		}
		if(d2 <= curDay) {
			total += v2;
		}
	
	}
	cout << curDay;
}
