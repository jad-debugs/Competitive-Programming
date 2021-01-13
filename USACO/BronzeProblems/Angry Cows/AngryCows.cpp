/*
6
8
5
6
13
3
4               
*/
#include <bits/stdc++.h>
using namespace std;

int simulate(int idx, vector<int> arr) {
	int radiusL = 1, radiusR = 1, ans = 1;
	int left = idx;
	int right = idx;

	while(left > 0 || right < arr.size()-1) {
		if(left > 0) {
			if(!(arr[left] - radiusL <= arr[left-1])) { // 3 4 5 6 8 13
				left = 0;
			}
			else {
				int tmpL = left;
				for(int i = left; i >= 0; i--) {
					if(arr[left] - radiusL <= arr[i]) {
						tmpL = i;
					}
				}
				radiusL++;
				ans += (left - tmpL);
				left = tmpL;
			}
		}

		if(right < arr.size()-1) {
			if(!(arr[right] + radiusR >= arr[right+1])) {
				right = arr.size()-1;
			}
			else {
			
				int tmpR = right;
				for(int i = right; i < arr.size(); i++) {
					if(arr[right] + radiusR >= arr[i]) {
						tmpR = i;
					}
				}
				radiusR++;
				ans += (tmpR - right);
				right = tmpR;
			}
		}

	}
	return ans;
}

int main() 
{
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
 	
 	int n; cin >> n;

 	vector<int> arr;

 	for(int i = 0; i < n; i++) {
 		int tmp; cin >> tmp;
 		arr.push_back(tmp);
 	}

 	sort(arr.begin(), arr.end());

 	int ans = 0;

 	for(int i = 0; i < n; i++) {
 		ans = max(ans, simulate(i, arr));
 	}

 	cout << ans;
 	return 0;
}

/*if(arr[right] + radiusR >= arr[right+1]) {
				radiusR++;
				ans++;
			}*/