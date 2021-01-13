#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int arr[7];

	for(int i = 0; i < 7; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+7);

	int abc = arr[6];

	int options[6];

	for(int i = 0; i < 6; i++) {
		options[i] = arr[i];
	}

	int a, b, c, ab, ac, bc;

	do {
		a = options[0]; b = options[1]; c = options[2];
		ab = options[3]; bc = options[4]; ac = options[5];

		if(a+b+c == abc) {
			if(a+b == ab) {
				if(a+c == ac) {
					if(b+c == bc) {
						break;
					}
					continue;
				}
				continue;
			}
			continue;
		}
		continue;

	} while (next_permutation(options, options+6));

	cout << a << " " << b << " " << c;

	return 0;
}