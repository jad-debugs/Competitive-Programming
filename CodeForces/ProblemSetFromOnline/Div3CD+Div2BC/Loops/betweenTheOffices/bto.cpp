#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;

    string s; cin >> s;

    int sf = 0, fs = 0;
        
    for(int i = 0; i < n-1; i++) {
        if(s.substr(i, 2) == "SF")
            sf++;
        else if (s.substr(i, 2) == "FS")
            fs++;
    }

    cout << (sf > fs ? "YES" : "NO");
}
