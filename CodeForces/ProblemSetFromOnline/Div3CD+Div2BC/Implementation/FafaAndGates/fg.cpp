#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n; cin >> n;
    string s; cin >> s;
        
    int x = 0, y = 0, coins = 0;

    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == 'U')
            y++;
        else
            x++;
        if(x==y && s[i] == s[i+1])
            coins++;
    }
    cout << coins;
}
