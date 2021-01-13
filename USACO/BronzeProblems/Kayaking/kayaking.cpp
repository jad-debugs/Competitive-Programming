#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, result = 0;
	cin >> n;
	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	arr.erase(arr.end()-1);
	arr.erase(arr.end()-1);

	for(int i = 1; i < n; i++){
		result += arr[i] - arr[i-1]; 
	}
	cout << result;
}
