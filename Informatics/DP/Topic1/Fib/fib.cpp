#include <iostream>
using namespace std;

long long dp[100] = {0};

long long fib(long long n)
{
    if (dp[n])
        return dp[n];
    if (n <= 2)
        return 1;
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

int main()
{
    cout << fib(45);
}