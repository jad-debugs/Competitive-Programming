#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long n;
	long long count = 0;
	cin >> n;
	long long arr[n];
	for(int in = 0; in < n; in++){
		cin >> arr[in];
	}

	for(long long i = 1; i < n; i++){
		if(arr[i] < arr[i-1]){
			count += (arr[i-1] - arr[i]);
			arr[i] += (arr[i-1] - arr[i]);
		}
	}
	cout << count;
}
