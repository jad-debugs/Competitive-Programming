#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    int n, m; cin >> n >> m;

    int tetris[n];

    for(int i = 0; i < n; i++)
        tetris[i] = 0;

    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        tetris[tmp-1]++;
    }
    
    int points = tetris[0];

    for(int i = 1; i < n; i++) {
        points = min(tetris[i], points);
    }

    cout << points;
    return 0;
}
