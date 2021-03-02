// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

bool valid_paren (string input, char one, char two, char three)
{
    for(auto &ch: input) {
        if (ch == 'A')
            ch = one;
        else if (ch == 'B')
            ch = two;
        else
            ch = three;
    }

    stack <char> s;
    int length = input.length();
    char top;
    for(int i = 0; i< length; i++) {
        if(input[i] == '(')
            s.push(input[i]);
        else {
         if(s.empty())
           return false;
          else { 
            top = s.top();
            if(input[i] == ')' && top == '(') {
                s.pop();
            }
                else
                    return false;
            }
        }
    }
    if (s.empty())
        return true;
    return false;
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
    setIO("");

    int t; cin >> t;

    while(t--) {
        string input; cin >> input;
        string temp = input;

        if(input[0] == 'A') {
            if(valid_paren(input, '(', '(', ')')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, '(', ')', ')')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, '(', ')', '(')) {
                cout << "Yes\n";
                continue;
            }
        }
        else if(input[0] == 'B') {
            if(valid_paren(input, ')', '(', ')')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, '(', '(', ')')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, ')', '(', '(')) {
                cout << "Yes\n";
                continue;
            }
        }
        else {
            if(valid_paren(input, ')', ')', '(')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, ')', '(', '(')) {
                cout << "Yes\n";
                continue;
            }
            else if (valid_paren(input, '(', ')', '(')) {
                cout << "Yes\n";
                continue;
            }
        }
        cout << "No\n";
    }

    return 0;
}
