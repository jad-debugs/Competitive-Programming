#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n; cin >> n;

	int flowers[n];

	for(int i = 0; i < n; i++) {
		cin >> flowers[i];
	}

	int ans = 0;

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			float sum = 0;

			for(int k = i; k <= j; k++) {
				sum += flowers[k];
			}

			int numbetween = j-i+1;

			float avg = sum/numbetween;

			for(int a = i; a <= j; a++) {
				if(flowers[a] == avg) {
					ans++;
					break;
				}
			}

			
		}
	}

	cout << ans;

	return 0;
}
/*if(between%2==1) {
				if(flowers[idx] == avg)
					ans++;
			}
			else {
				if(flowers[idx] == avg || flowers[idx+1] == avg)
					ans++;
			}*/