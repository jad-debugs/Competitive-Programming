#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n; cin >> n;
    string str; cin >> str;
    map<string, int> map;

    for (int i = 1; i < n; i++) {
        string tmp = "";
        tmp += str[i-1];
        tmp += str[i];
        map[tmp]++;
    }
    string ansS = "";
    int ans = 0;
    for (pair<string, int> x: map) {
        if (x.second > ans) {
            ansS = x.first;
            ans = x.second;
        }
    }
    cout << ansS;
    return 0;
}
