#include <bits/stdc++.h>
using namespace std;
int main () 
{
	bool flag = true;
	long long n;
	cin >> n;
	long long arr[n-1];
	long long base[n];

	for(long long a  = 0; a < n-1; a++){
		cin >> arr[a];
	}

	for(long long b = 0; b < n; b++){
		base[b] = b+1;
	}

	sort(arr, arr+n);

	for(long long i = 0; i < n; i++)
	{
		if(arr[i] != base[i]){
			flag = false;
			cout << i+1;
			break;
		}
	}
	
	if(flag)
		cout << base[n-2];

	return 0;
}