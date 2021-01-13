#include <iostream>
using namespace std;

void toggleCaps(string word) {
    for(char &x: word) {
        if(x < 97)
            x += 32;
        else
            x -= 32;
    }
    cout << word;
}

int main()
{
    string word; cin >> word;
    bool rest = true; 
    if(word[0] >= 97) {
        // check rest
        for(int i = 1; i < word.size(); i++) {
            if(word[i] >= 97) {
                rest = false;
            }
        }
        if(!rest) {
            cout << word;
            return 0;
        }
        else {
            toggleCaps(word);
            return 0;
        }
    }
    else {
        for(char x: word) {
            if(x >= 97)
                rest = false;
        } 
    }
    if(rest)
        toggleCaps(word);
    else
        cout << word;
    return 0;
}
