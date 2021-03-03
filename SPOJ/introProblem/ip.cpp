#include <iostream>
using namespace std;

int main()
{
    int n;

    while(cin >> n) {
        if (n == 42)
            break;
        cout << n << "\n";
    }
    return 0;
}