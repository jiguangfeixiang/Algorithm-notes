#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        // dp[i][j] 表示 text1 前 i 个字符与 text2 前 j 个字符的 LCS 长度
        // 维度为 (m + 1) x (n + 1)，默认初始化为 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // 如果当前字符匹配
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                // 如果不匹配，二选一取最大值
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 最终答案在右下角
        return dp[n][m];
    }
};