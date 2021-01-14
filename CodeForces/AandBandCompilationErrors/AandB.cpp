#include <bits/stdc++.h>
using namespace std;

int main() {
    const int hi = 1e9+2;
    int n; cin >> n;
    
    int arrF[n];
    int arrS[n-1]; 
    map<int, int> first;
    map<int, int> second;
    map<int, int> third;
    // first line in
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        arrF[i] = a;
        first[a]++;
    }
    for(int i = 0; i < n-1; i++) {
        int b; cin >> b;
        arrS[i] = b;
        second[b]++;
    }
    for(int i = 0; i < n-2; i++) {
        int c; cin >> c;
        third[c]++;
    }

    for(int i : arrF) {
        if(first[i] != second[i]) {
            cout << i << "\n";
            break;
        }
    }
    for(int i : arrS) {
        if(second[i] != third[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}