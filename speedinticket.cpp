#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    int n, m, tmp, tmp1;
    vector<int> distance;
    vector<int> bessie_distance;
    vector<int> bessie_speed;
    vector<int> speed_limits;
    vector<int> limits;
    vector<int> bessie;
    int mph = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> tmp >> tmp1;
        distance.push_back(tmp);
        speed_limits.push_back(tmp1);
    }

    for(int i = 0; i < m; i++){
        cin >> tmp >> tmp1;
        bessie_distance.push_back(tmp);
        bessie_speed.push_back(tmp1);
    }
    
    for(int a = 0; a < n; a++){
        for(int b = 0; b < distance[a]; b++){
            limits.push_back(speed_limits[a]);
        }
    }

    for(int a = 0; a < m; a++){
        for(int b = 0; b < bessie_distance[a]; b++){
            bessie.push_back(bessie_speed[a]);
        }
    }

    for(int i = 0; i < 100; i++){
       mph = max(mph, bessie[i]-limits[i]);
    }
   

    cout << mph;
    return 0;
}
