#include <iostream>
#include <set>
using namespace std;

int main()
{
    string word; cin >> word;
    
    set<char> letters;

    for(char x: word)
        letters.insert(x);
    if(letters.size()%2 == 1)
       cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}
