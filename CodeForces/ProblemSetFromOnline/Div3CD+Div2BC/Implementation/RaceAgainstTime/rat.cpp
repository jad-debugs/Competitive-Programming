#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    vector<int> vec(5);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h *= 5; t1 *= 5; t2 *= 5;

    vec[0] = h; vec[1] = m; vec[2] = s; vec[3] = t1; vec[4] = t2;
    
    for(int i = 0; i < 5; i++) {
        if(vec[i] == 0) {
            vec[i] = 60;
        }
    }

    sort(vec.begin(), vec.end());
    
    if(vec[0] == t1 && vec[4] == t2) {
        cout << "YES";
        return 0;
    }
    
    bool beforeHand = false;
    for(int i = 0; i < 5; i++) {
        if(vec[i] == t1 || vec[i] == t2) {
            if(beforeHand) {
                cout << "YES";
                return 0;
            }
            beforeHand = true;
            continue;
        }
        beforeHand = false;
    }
    cout << "NO";
    return 0;
}
