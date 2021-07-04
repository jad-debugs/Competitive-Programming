#include <bits/stdc++.h>
using namespace std;

const int offset = 100;

int main() {
    int n; cin >> n;

    vector<int> sol(n+offset, n+1);
    sol[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int curX = q.front();
        q.pop();

        int nextX = 3*curX;
        if (nextX >= 1 && nextX < n+offset && sol[nextX] > sol[curX]+1) {
            sol[nextX] = sol[curX]+1;
            q.push(nextX);
        }

        nextX = curX-1;
        if (nextX >= 1 && nextX < n+offset && sol[nextX] > sol[curX]+1) {
            sol[nextX] = sol[curX]+1;
            q.push(nextX);
        }

        nextX = curX+1;
        if (nextX >= 1 && nextX < n+offset && sol[nextX] > sol[curX]+1) {
            sol[nextX] = sol[curX]+1;
            q.push(nextX);
        }
    }

    cout << sol[n];

    return 0;
}
