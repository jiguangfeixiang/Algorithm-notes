// “动态规划的有向无环推进（按列/行滚动），但局部允许双向移动”模型。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 设为一个极大的值，因为有负数，用来表示不可达

int main() {
    // 提升输入输出流速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // w 存地图权重，编号从 1 到 n，1 到 m
    vector<vector<long long>> w(n + 2, vector<long long>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> w[i][j];
        }
    }

    // up[i][j] 表示在第 j 列，通过向上走或从左跨过来到达 (i, j) 的最大值
    // down[i][j] 表示在第 j 列，通过向下走或从左跨过来到达 (i, j) 的最大值
    vector<vector<long long>> up(n + 2, vector<long long>(m + 2, -INF));
    vector<vector<long long>> down(n + 2, vector<long long>(m + 2, -INF));

    // ==================== 1. 初始化第一列 ====================
    // 第一列只能从 (1,1) 一路向下走，绝对不可能向上走，因为起点在最上面
    down[1][1] = w[1][1];
    for (int i = 2; i <= n; ++i) {
        down[i][1] = down[i - 1][1] + w[i][1];
    }
    // 第一列的 up 状态在此题中不需要，因为无法从下方走上来（左边没数据，不能绕过去）

    // ==================== 2. 按列推进动态规划 ====================
    for (int j = 2; j <= m; ++j) {
        
        // 步骤 A: 从上往下扫描，计算 down 状态
        for (int i = 1; i <= n; ++i) {
            // 首先考虑从左边那一列跨过来的情况
            long long from_left = max(up[i][j - 1], down[i][j - 1]);
            
            if (i == 1) {
                // 第一行没有上方格子，只能从左边跨过来
                if (from_left != -INF) down[i][j] = from_left + w[i][j];
            } else {
                // 可以从左边来，也可以从上面走下来
                long long best_prev = max(from_left, down[i - 1][j]);
                if (best_prev != -INF) down[i][j] = best_prev + w[i][j];
            }
        }

        // 步骤 B: 从下往上扫描，计算 up 状态
        for (int i = n; i >= 1; --i) {
            // 首先考虑从左边那一列跨过来的情况
            long long from_left = max(up[i][j - 1], down[i][j - 1]);
            
            if (i == n) {
                // 最后一行没有下方格子，只能从左边跨过来
                if (from_left != -INF) up[i][j] = from_left + w[i][j];
            } else {
                // 可以从左边来，也可以从下面走上来
                long long best_prev = max(from_left, up[i + 1][j]);
                if (best_prev != -INF) up[i][j] = best_prev + w[i][j];
            }
        }
    }

    // 最终答案即为到达终点 (n, m) 的两种路径形态的最大值
    cout << max(up[n][m], down[n][m]) << "\n";

    return 0;
}