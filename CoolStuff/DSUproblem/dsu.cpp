#include <iostream>
using namespace std;

struct DSU
{
    vector<int> v;
    DSU(int N) {
        v = vector<int>(N, -1);
    }

    int get(int x) {
        while (x != tmp)
            x = tmp;
        return x;
    }

    bool same(int a, int b) {
        return get(a) == get(b);
    }

    int size(int x) {
        return 
    }
}

int main()
{
    
}
