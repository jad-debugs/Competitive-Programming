#include <bits/stdc++.h>
using namespace std;

struct cow {
    int x, y;
};

bool cmpN(cow a, cow o)
{
    return a.x < o.x;
}

bool cmpE(cow a, cow o)
{
    return a.y < o.y;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    cow arr[n];
    vector<cow> arrE;
    vector<cow> arrN;

    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        int x, y; cin >> x >> y;
        if(ch == 'E')
            arrE.push_back({x, y});
        else
            arrN.push_back({x, y});
        arr[i] = {x, y};
    }

    sort(arrE.begin(), arrE.end(), cmpE);
    sort(arrN.begin(), arrN.end(), cmpN);

    map<int, bool> blocked;
    unordered_map<int, int> answers;

    for(int i = 0; i < n; i++) {
        if(arrE.size() > i) answers[arrE[i].x] = 0;
        if(arrN.size() > i) answers[arrN[i].x] = 0;
    }

    for(cow north: arrN) {
        for(cow east: arrE) {
            if(blocked[north.x] || blocked[east.x]) continue;
            if(!(north.x > east.x && north.y < east.y)) continue;
            int e_p = north.x - east.x;
            int n_p = east.y - north.y;

            if(n_p > e_p) {
                answers[east.x] += 1 + answers[north.x];
                blocked[north.x] = true;
            }
            else if(e_p > n_p) {
                answers[north.x] += 1 + answers[east.x];
                blocked[east.x] = true;
            }
        }
    }

    cerr << "size of answers " << answers.size()
        << "\n size of blocked " << blocked.size()
        << "size of arrE, arrN " << arrE.size() << ", " << arrN.size() << "\n"; 

    for(int i = 0; i < n; i++) {
        for(auto ans: answers) {
            if(ans.first == arr[i].x)
                cout << ans.second << "\n";
        }
    }

    return 0;
}