// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
typedef pair<int, int> pii;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}

struct interval {
    int st, en, idx;
};

bool cmp(interval p1, interval p2)
{
    return p1.st < p2.st;
}

int main()
{
    setIO();

    int t; cin >> t;

    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int n; cin >> n;
        interval arr[n];
        for(int a = 0; a < n; a++) {
            int in1, in2; 
            cin >> in1 >> in2;
            arr[a] = {in1, in2, a};
        }
        
        sort(arr, arr+n, cmp);

        vector<char> schedule(n);

        schedule[arr[0].idx] = 'J';
        schedule[arr[1].idx] = 'C';

        int Jend = arr[0].en;
        int Cend = arr[1].en;

        bool imp = false;

        for(int i = 2; i < n; i++) {
            if(arr[i].st >= Jend) {
                schedule[arr[i].idx] = 'J';
                Jend = arr[i].en;
            }
            else if(arr[i].st >= Cend) {
                schedule[arr[i].idx] = 'C';
                Cend = arr[i].en;
            }
            else {
                imp = true;
            }
        }
        if(imp) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            cout << schedule[i];
        }
        cout << "\n";
    }

    return 0;
}
