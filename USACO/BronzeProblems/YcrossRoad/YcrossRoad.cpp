#include <bits/stdc++.h>
using namespace std;

int main ()
{
	freopen("cowqueue.in","r",stdin);
 	freopen("cowqueue.out","w",stdout);
	int n, result = 0;
	cin >> n;
	map<int, int> data;
	int indexes[n];

	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		indexes[i] = tmp;
		cin >> data[tmp];
	}

	sort(indexes, indexes + n);
	result += indexes[0] + data[indexes[0]];
	for(int i = 1; i < n; i++){
		if(result < indexes[i]){
			result = indexes[i];
		}
		result+=data[indexes[i]];
	}

	cout << result;
}
