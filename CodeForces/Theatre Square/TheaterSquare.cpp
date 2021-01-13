#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double n, m, a, l,k;
	cin >> n >> m >> a;

	l = ceil(n/a); k = ceil(m/a);

	long long ans = (long long)(l*k);
	cout << ans;
}