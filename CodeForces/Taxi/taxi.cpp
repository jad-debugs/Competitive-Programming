#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    
    int numsOfNum[4] = {0, 0, 0, 0};

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        numsOfNum[arr[i]-1]++;
    } 
    int cars = numsOfNum[3];
    if(int m = min(numsOfNum[0], numsOfNum[2])) {
        numsOfNum[0] -= m;
        numsOfNum[2] -= m;
        cars += m;
    } 
    cars += numsOfNum[2];
    // if 2's are even
    if(numsOfNum[1]%2 == 0) {
        cars += numsOfNum[1]/2;
        // get rest of ones
        if(numsOfNum[0]%4==0)
            cars+=numsOfNum[0]/4;
        else
            cars+=(numsOfNum[0]/4+1);
    }
    // if 2's are not even
   
    else {
        cars += numsOfNum[1]/2;
        numsOfNum[1] = 1;
        cars++;
        if(numsOfNum[0] > 2) {
            numsOfNum[0] -= 2;
            if(numsOfNum[0]%4==0) {
                cars += numsOfNum[0]/4;
            }
            else {
                cars += (numsOfNum[0]/4 + 1);
            }
        }
    }
    
    cout << cars;
   
    return 0;
} 
