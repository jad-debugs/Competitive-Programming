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

int n, q;

void gen(vector<int> &pf, string str)
{
    stack<char> stack;
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (stack.empty() || stack.top() < ch) {
            stack.push(ch);
            pf[i+1] = pf[i]+1;
        }
        else {
            while (!stack.empty() && stack.top() > ch) {
                stack.pop();
            }
            if (stack.empty() || stack.top() < ch) {
                pf[i+1]  = pf[i]+1;
                stack.push(ch);
            }
            else
                pf[i+1] = pf[i];
        }
    }
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

    cin >> n >> q;

    string front, back;
    cin >> front;

    back = front;
    reverse(back.begin(), back.end());

    vector<int> pf1(n+1);
    vector<int> pf2(n+1);

    gen(pf1, front);
    gen(pf2, back);

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pf1[a-1] + pf2[n-b] << "\n";
    }

    return 0;
}
