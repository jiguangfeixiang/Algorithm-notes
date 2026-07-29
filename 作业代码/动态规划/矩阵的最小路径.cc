#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        // dp[i][j] 表示到达 (i, j) 的最小路径和
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // 1. 初始化起点
        dp[0][0] = matrix[0][0];

        // 2. 初始化第一列（只能向下走）
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        // 3. 初始化第一行（只能向右走）
        for (int j = 1; j < m; ++j) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }

        // 4. 填充剩余网格
        for (int i = 1; i < n; ++i) { 
            for (int j = 1; j < m; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            }
        }

        // 返回右下角结果
        return dp[n - 1][m - 1];
    }
};
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        // 哨兵值：用一个足够大的数代表正无穷（注意防溢出，选 0x3f3f3f3f）
        const int INF = 0x3f3f3f3f;
        
        // 开 (n + 1) * (m + 1) 大小的 dp 数组，全部初始化为 INF
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

        // 核心破局：设置起点的触发开关（让 dp[1][1] 能够算出正确结果）
        dp[0][1] = 0; // 或者设 dp[1][0] = 0 都可以

        // 主循环没有任何一个 if 特判！
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        
        // 防溢出的无穷大哨兵值
        const int INF = 0x3f3f3f3f;

        // 1. 开辟 m + 1 大小的一维滚动数组，全部填满 INF
        // dp[0] 作为左侧哨兵，dp[1..m] 存储每列的状态
        vector<int> dp(m + 1, INF);

        // 2. 破局触发器：设置 dp[1] = 0
        // 使得计算起点 (0, 0) 时：min(dp[1], dp[0]) + matrix[0][0] = min(0, INF) + val = val
        dp[1] = 0; 

        // 3. 逐行向下滚动，双重循环内部零特判！
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // dp[j]     : 正上方（上一行的旧值）
                // dp[j - 1] : 正左方（这一行刚更新的最新值）
                dp[j] = min(dp[j], dp[j - 1]) + matrix[i][j - 1];
            }
        }

        // 4. 最终答案保存在 dp[m] 中
        return dp[m];
    }
};