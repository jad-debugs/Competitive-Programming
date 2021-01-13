#include <iostream>
#include <cmath>
using namespace std;
int *locateOne(int arr[5][5]) {
	int static loc[2];	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(arr[i][j] == 1) {
				loc[0] = i;
				loc[1] = j;
			}
		}
	}
	return loc;	
}

int main()
{	
	int arr[5][5];

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> arr[i][j];	
		}
	}
	
	int *ans = locateOne(arr);
	
	cout << abs(ans[0] - 2) + abs(ans[1] - 2);  	

	return 0;
}

