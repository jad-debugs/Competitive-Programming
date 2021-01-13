#include <iostream>
using namespace std;

struct Cow {
	char dir;
	int x, y;

	bool checkIntersect(Cow other, int diff) {
		int intersect[2];
		if(dir == 'E') {
			intersect[0] = x + diff;
			intersect[1] = y;
		}
		else {
			intersect[0] = x;
			intersect[1] = y + diff;
		}

		// cant think of a way to check if the crossPath is valid
		// these seems way too hard

	}

	int crossPaths(Cow other) {
		// returns [value between, point intersect X, point intersect Y]
		if(dir == 'E' && other.dir == 'N') {
			if(x < other.x) {
				int diff = other.x - x;
				if(y < other.y+diff)
					return diff;
			}
		}
		else if (dir == 'N' && other.dir == 'E') {
			if(y < other.y) {
				int diff = other.y - y;
				if(x < other.x+diff)
					return diff;
			}
		}
		return 1e9+1;
	}	
};

int main()
{
	int n;
	cin >> n;
	Cow arrayOfCows[n];

	for(int i = 0; i < n; i++) {
		cin >> arrayOfCows[i].dir >> arrayOfCows[i].x >> arrayOfCows[i].y;
	}

	int ans[n];

	for(int i = 0; i < n; i++) {
		ans[i] = 1e9+1;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			ans[i] = min(arrayOfCows[i].crossPaths(arrayOfCows[(i+j)%n]), ans[i]);
			cout << arrayOfCows[i].crossPaths(arrayOfCows[(i+j)%n]) << " ";
		}
		cout << "\n";
	}

	for(int i = 0; i < n; i++) {
		if(ans[i] == 1e9+1)
			cout << "Infinity";
		else
			cout << ans[i];
		cout << "\n";
	}	

}


/*
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
*/