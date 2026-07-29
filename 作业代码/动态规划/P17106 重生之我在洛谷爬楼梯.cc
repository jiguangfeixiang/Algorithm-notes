// 重生之我在洛谷爬楼梯
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // 创建一个二维向量dp，大小为(n+1)×3，初始化为0
    // dp[i][1]表示第i个台阶最后一步走1个台阶的走法数
    // dp[i][2]表示第i个台阶最后一步走2个台阶的走法数
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    // 特殊情况处理：当n=1时，只有一种走法
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    long long ans = 0;

    // 初始化第1个台阶和第2个台阶的走法数
    dp[2][2] = 1;  // 第2个台阶最后一步走2个台阶的走法数
    dp[1][1] = 1;  // 第1个台阶最后一步走1个台阶的走法数
    dp[2][1] = 1;  // 第2个台阶最后一步走1个台阶的走法数
    // 从第3个台阶开始，递推计算每个台阶的走法数
    for (int i = 3; i <= n; i++)
    {

        // 当前台阶最后一步走1个台阶的走法数 = 前一个台阶的所有走法数
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
        // 当前台阶最后一步走2个台阶的走法数 = 前两个台阶最后一步走1个台阶的走法数
        dp[i][2] = dp[i - 2][1];
    }

    // 计算总走法数 = 最后一步走1个台阶的走法数 + 最后一步走2个台阶的走法数
    ans = dp[n][1] + dp[n][2];
    cout << ans;
    return 0;
}