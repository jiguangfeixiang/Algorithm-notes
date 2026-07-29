#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // 1. 定义 DP 数组
        vector<int> dp(n, 0);

        // 2. 初始化边界
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        // 3. 递推计算
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 4. 返回偷完全部房屋的最大收益
        return dp[n];
    }
};