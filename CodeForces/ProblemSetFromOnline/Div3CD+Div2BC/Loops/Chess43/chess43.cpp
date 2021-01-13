#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    
    int spectator = 3, p1 = 1, p2 = 2;
    while(n--) {
        int winner; cin >> winner;
        if(winner == spectator) {
            cout << "NO";
            return 0;
        }
        if(p1 == winner) {
            p1 = winner;
            swap(spectator, p2);
        }
        if(p2 == winner) {
            p2 = winner;
            swap(spectator, p1);
        }

    }
    cout << "YES";
    return 0;
}
