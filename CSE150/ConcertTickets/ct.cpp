#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    
    int ppl[m];
    priority_queue<int> tickets;

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        tickets.push(tmp);
    }

    for(int i = 0; i < m; i++) {
        cin >> ppl[i];
    }

    for(int x : ppl) {
        int *p = tickets.lower_bound(x);
        if(*p == x) {
            cout << x << "\n";
            tickets.erase(p);
        }
        else if(p == tickets.begin()) cout << -1 << "\n";
        else cout << *(--p) << "\n";
    }

    return 0 ;
}
