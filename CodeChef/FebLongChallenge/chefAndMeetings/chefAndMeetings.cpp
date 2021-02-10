// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    /*
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    */
}


int main()
{
    setIO();

    int t; cin >> t;
    while(t--) {
        int hours; cin >> hours;
        char ig; cin >> ig;
        int minutes; cin >> minutes;
        string time; cin >> time;

        int multi = 1;

        if(time == "PM")
            multi = 60;

        int org = multi*60*hours + minutes; 

        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int h1; cin >> h1;
            cin >> ig;
            int m1; cin >> m1;
            string t1; cin >> t1;

            int h2; cin >> h2;
            cin >> ig;
            int m2; cin >> m2;
            string t2; cin >> t2;

            int l = 60*h1 + m1;
            int r = 60*h2 + m2;

            if(t1 == "PM") {
                l += 60*12;
            }
            if(t2 == "PM") {
                r += 60*12;
            }
            cout << l << " " << org << " " << r << "\n";
            // if(l <= org && org <= r) {
                
            //     //cout << "1";
            // }
            // else
            //     cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
