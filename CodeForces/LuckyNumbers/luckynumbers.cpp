#include <iostream>
#include <string>
using namespace std;

bool ChecksLucky(int n)
{
     string number = to_string(n);
     bool isLucky = true;
     for(char x: number) {
        if(x != '7' && x != '4')
            isLucky=false;
     }
        if(isLucky) {
            return true;
        }
    return false; 
}

int main()
{
    int n; cin >> n;
    // check if number lucky
    if(ChecksLucky(n)) {
        cout << "YES";
        return 0;
    }

    for(int i = 4; i < n; i++) {
        if(n%i==0) {
            if(ChecksLucky(i)) {
                cout << "YES";
                return 0;
            }
        }
    } 
    cout << "NO";
    return 0;
}
