#include <iostream>
#include <algorithm>
using namespace std;

string reverseStr(const string a) 
{
    string ans = "";
    for(int i = a.size()-1; i >= 0; i--) {
        ans += a[i];
    }
    return ans;
}

int main()
{
    string pass; cin >> pass;
    int n; cin >> n;
    bool f = false, b = false;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        if(tmp == pass || tmp == reverseStr(pass)) {
            cout << "YES";
            return 0;
        }
        else if(!f && (tmp[0] == pass[1]))
            f = true;
        else if(!b && (tmp[1] == pass[0]))
            b = true;
        if(f && b) {
            cout << "YES";
            return 0;
        }
    } 

    cout << "NO";
     
    return 0;    
}
