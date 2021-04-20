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

int MX = 0;

bool cmp(string a, string b)
{
    return a + b < b + a;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
}


int main()
{
    setIO("");

    int n; cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}
