// 下楼梯
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// int fib(int n){
//     if (n==1)
//     {
//         return 1;
//     }
//     if (n==2)
//     {
//         return 2;
//     }
//     if (n==3)
//     {
//         return 4;
//     }
//     return fib(n - 1) + fib(n - 2) + fib(n - 3);
// }
//
// vector<int> dp(100,-1);
// int fib(int n){
//     if (dp[n]!=-1)
//     {
//         return dp[n];
//     }
    
//     if (n==1)
//     {
//         return 1;
//     }
//     if (n==2)
//     {
//         return 2;
//     }
//     if (n==3)
//     {
//         return 4;
//     }
//     dp[n]=fib(n - 1) + fib(n - 2) + fib(n - 3);
//     return dp[n];
// }
vector<long long> dp(100,-1);
// long long fib(int n){
//     if (dp[n]!=-1)
//     {
//         return dp[n];
//     }
    
//     if (n==1)
//     {
//         return 1;
//     }
//     if (n==2)
//     {
//         return 2;
//     }
//     if (n==3)
//     {
//         return 4;
//     }
//     dp[n]=fib(n - 1) + fib(n - 2) + fib(n - 3);
//     return dp[n];
// }
long long fib(int n){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <=n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    long long res=fib(n);
    cout << res;
    return 0;
}