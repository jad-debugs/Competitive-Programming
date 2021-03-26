#include <bits/stdc++.h>
using namespaces std;

void solve()
{
	int n,counter = 0;;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int a = 1; a < n;a++){
		if(arr[a] - arr[a-1] <= 1){
				arr[i-1] = 101;
		}
	}
	for(int i = 0 ;i < n; i++){
		if(arr[i] != 101)
			counter++;
	}
	if(counter == 1)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}

