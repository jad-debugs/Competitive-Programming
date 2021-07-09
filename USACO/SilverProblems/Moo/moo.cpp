#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n;

char go(int i)
{
    int len = 3, midlen = 3;
    while (len <= i) {
        midlen++;
        len = 2*len+midlen;
    }
    int prelen = (len-midlen)/2;
    if (i > prelen + midlen)
        return go(i - (prelen+midlen));
    if (i == prelen+1)
        return 'm';
    return 'O';
}

int main()
{
    cin >> n;

    cout << go(n) << '\n';

    return 0;
}
