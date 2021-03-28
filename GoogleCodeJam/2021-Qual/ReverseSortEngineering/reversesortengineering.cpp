#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// lol just straight brute force

int countCost(vector<int> v, int n)
{
    int cost = 0;
    for (int i = 0; i < n-1; i++) {
        int mn = 101;
        int idx = 0;

        for (int j = i; j < n; j++) {
            if (v[j] < mn) {
                mn = v[j];
                idx = j;
            }
        }
        
        cost += idx - i + 1;
        reverse(v.begin()+i, v.begin()+idx+1);
    }
    return cost;
}

int main()
{
    int t; cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";
        
        int n, c; cin >> n >> c;
        vector<int> v(n);
        
        for (int i = 0; i < n; i++) {
            v[i] = i+1;
        }
        
        bool flag = false;
        do {
            if (countCost(v, n) == c) {
                flag = true;
                break;
            }
        } while (next_permutation(v.begin(), v.end())); 

        if (!flag)
            cout << "IMPOSSIBLE";
        else {
            for (int x: v)
                cout << x << ' ';
        }
        cout << "\n"; 
    }
    return 0;
}

