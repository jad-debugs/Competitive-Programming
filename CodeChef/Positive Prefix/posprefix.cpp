#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t; cin >> t;
	vector<vector<int> > answers;
	while(t--) {

		int n, k; cin >> n >> k;
		vector<int> tmp;
		for(int i = 1; i <= n; i++) {
			tmp.push_back(i);
		}
		if(n == k)
			answers.push_back(tmp);
		else if(k < n/2) {
			for(int i = 0; i < k*2; i++) {
				if(tmp[i]%2!=0)
					tmp[i] = -tmp[i];
			}
		}
		else if(k > n/2) {
			for(int i = 0; i < k; i++) {
				if(tmp[i]%2!=0)
					tmp[i] = -tmp[i];
			}
		}

	}


	for(int i = 0; i < answers.size(); i++) {
		for(int j = 0; j < answers[i].size(); j++) {
			cout << answers[i][j] << " ";
		}
		cout << "\n";
	}

}