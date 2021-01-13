#include <iostream>
using namespace std;

int main()
{
    int s, t1, t2, v1, v2; cin >> s >> v1 >> v2 >> t1 >> t2;
    int p1, p2;
    p1 = s*v1 + 2*t1;
    p2 = s*v2+ 2*t2;
    if(p1 < p2)
        cout << "First";
    else if(p1 > p2)
        cout << "Second";
    else
        cout << "Friendship";
    return 0;
}
