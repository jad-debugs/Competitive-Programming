#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, target;
	cin >> n >> target;
	map<int, int> map;
	int arr[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
        if(map.count(target - arr[i])){
        	cout << i << endl;
            cout << i + 1 << " " << map[target - arr[i]] << "\n";
            return 0;
        }
        map[arr[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << '\n';
}
