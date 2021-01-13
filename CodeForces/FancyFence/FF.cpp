#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;
    
    while(n--) {
        int angle; cin >> angle;
        int posI; float posF;
        if(angle < 60 || angle == 180) {
            cout << "NO" << "\n";
            continue;
        }
        posI = 360/(180 - angle);
        posF = float(360)/(180 - angle);
        if(posI == posF) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
