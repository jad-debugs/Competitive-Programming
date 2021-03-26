#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long x[n];
	long long y[n];
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for(long long i = 0; i < n; i++)
	{
		long long max1 = max(x[i], y[i]);
		long long max2 = (max1-1)*(max1-1);
		if(max1 % 2 == 0){
			if(max1 == y[i])
				cout << max2+x[i] << endl;
			else
				cout << max2+2*max1-y[i];
		} else {
			if(max1 == x[i])
				cout << max2 + y[i] << endl;
			else
				cout << max2 + 2 * max1 - x[i] << endl;
		}

	}
	return 0;
}
