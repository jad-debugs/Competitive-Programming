/* 
ID: jadDebugs
TASK: friday
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

// 0 is saturday, friday is 6
int week[7] = {0};

bool leapYear(int year)
{
    if (year == 1900 || year == 2100 || year == 2200 || year == 2300)
        return false;
    else if (year%4 == 0)
        return true;
    return false;
}

void dayOf13(int year, int &day)
{
    // 12 loop +arr or brute 12 eh

    // jan
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // feb
    if (leapYear(year)) {
        day = (5+day)%7; week[day]++; day = (3+day)%7;
    }
    else {
        day = (5+day)%7; week[day]++; day = (2+day)%7;
    }
    // march
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // april
    day = (5+day)%7; week[day]++; day = (4+day)%7;
    // may
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // june
    day = (5+day)%7; week[day]++; day = (4+day)%7;
    // july
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // august
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // sept
    day = (5+day)%7; week[day]++; day = (4+day)%7;
    // oct
    day = (5+day)%7; week[day]++; day = (5+day)%7;
    // nov
    day = (5+day)%7; week[day]++; day = (4+day)%7;
    // dec
    day = (5+day)%7; week[day]++; day = (5+day)%7;
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
    setIO("friday");

    int n; cin >> n;

    int curDay = 2; // monday

    for (int i = 0; i < n; i++) {
        dayOf13(1900 + i, curDay);
    }

    for (int i = 0; i < 6; i++)
        cout << week[i] << ' ';
    cout << week[6] << '\n';

    return 0;
}
