#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始化 dp 数组，长度为 amount + 1，默认值设为 amount + 1（相当于无穷大）
        vector<int> dp(amount + 1, amount + 1);
        
        // 基础状态：凑成金额 0 需要 0 个硬币
        dp[0] = 0;
        
        // 外层循环递增遍历每一个金额
        for (int i = 1; i <= amount; ++i) {
            // 内层循环遍历每一种硬币
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // 如果 dp[amount] 依然大于 amount，说明无法凑出该金额
        return dp[amount] > amount ? -1 : dp[amount];
    }
};