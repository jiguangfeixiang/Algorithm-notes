#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义点结构体
struct Point {
    long long x, y;

    // 按 x 从小到大排序，x 相同的按 y 从小到大排序
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<Point> pts(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    // 1. 按照坐标顺序排序，保证状态转移方向天然有序
    sort(pts.begin() + 1, pts.end());

    // dp[i][p]: 以第 i 个点结尾，已使用 p 个自由点时的最大序列长度
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    int ans = 0;

    // 2. 动态规划过程
    for (int i = 1; i <= n; ++i) {
        // 初始化：以 pts[i] 结尾，基础长度为 1，加上消耗的 p 个自由点
        for (int p = 0; p <= k; ++p) {
            dp[i][p] = 1 + p;
        }

        // 遍历前面的点 j，尝试从 j 转移到 i
        for (int j = 1; j < i; ++j) {
            // 只有当 j 位于 i 的左下角（包含水平/垂直）时才可以连接
            if (pts[j].x <= pts[i].x && pts[j].y <= pts[i].y) {
                // 计算从 j 到 i 需要补充的点数
                int need = (pts[i].x - pts[j].x) + (pts[i].y - pts[j].y) - 1;

                // 枚举在 i 处已使用的自由点总数 p
                for (int p = need; p <= k; ++p) {
                    dp[i][p] = max(dp[i][p], dp[j][p - need] + need + 1);
                }
            }
        }

        // 统计答案：把剩余没用完的自由点 (k - p) 接在点 i 后面
        for (int p = 0; p <= k; ++p) {
            ans = max(ans, dp[i][p] + (k - p));
        }
    }

    cout << ans << "\n";

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// struct Point {
//     int x, y;
//     // 按 x 升序排序，x 相同按 y 升序排序
//     bool operator<(const Point& other) const {
//         if (x != other.x) return x < other.x;
//         return y < other.y;
//     }
// } p[505];

// int main() {
//     // 快速输入输出
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     if (!(cin >> n >> k)) return 0;

//     for (int i = 1; i <= n; i++) {
//         cin >> p[i].x >> p[i].y;
//     }

//     // 仅针对 k == 0 的特判/偷分逻辑
//     if (k == 0) {
//         // 1. 排序：确保处理顺序是从左到右、从下到上
//         sort(p + 1, p + n + 1);

//         vector<int> dp(n + 1, 1); // dp[i] 表示以第 i 个点结尾的最长路径点数
//         int max_ans = 1;

//         // 2. 动态规划查找最长连通路径
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j < i; j++) {
//                 // 确保点 i 在点 j 的右上方向（或正右、正上）
//                 if (p[i].x >= p[j].x && p[i].y >= p[j].y) {
//                     // 核心条件：两点距离恰好为 1（只能向右移1格或向上移1格）
//                     if ((p[i].x - p[j].x) + (p[i].y - p[j].y) == 1) {
//                         dp[i] = max(dp[i], dp[j] + 1);
//                     }
//                 }
//             }
//             max_ans = max(max_ans, dp[i]);
//         }

//         cout << max_ans << "\n";
//         return 0; // 抢完 k=0 的分直接退出
//     }

//     // 如果 k != 0 且不想写正解，可以输出 1 或 k+1 保底
//     cout << k + 1 << "\n";

//     return 0;
// }