#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


int main()
{
    setIO("homework");

    int n; cin >> n;

    int scores[n];
    int pfS[n];
    int pf = 0;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        pf += scores[i];
        pfS[i] = pf;
    }

    int lows[n];

    for (int i = n-1; i > 0; i--) {
        if (i == n-1)
            lows[i-1] = scores[i];
        else
            lows[i-1] = min(scores[i], lows[i]);
    }
    vector<int> results; 
    float avg = 0;
    for (int i = 0; i < n-2; i++) {
        float tmpAvg = (pfS[n-1] - pfS[i] - lows[i])/(1.0*n - 2.0 - i);
        
        if (tmpAvg > avg) {
            avg = tmpAvg;
            results.clear();
            results.push_back(i+1);
        }
        else if (tmpAvg == avg)
            results.push_back(i+1);
    }

    for(int x: results)
        cout << x << "\n";
    return 0;
}
