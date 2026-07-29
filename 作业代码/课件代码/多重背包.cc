// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     // 优化 I/O 速度
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, T;
//     if (!(cin >> n >> T)) return 0;

//     // dp[j] 表示承重为 j 时的最大价值
//     vector<int> dp(T + 1, 0);

//     for (int i = 0; i < n; ++i) {
//         int x, w, v;
//         cin >> x >> w >> v;

//         // 将 x 个物品展开成 x 个独立物品处理（0-1背包）
//         for (int k = 0; k < x; ++k) {
//             // 0-1 背包倒序遍历容量
//             for (int j = T; j >= w; --j) {
//                 dp[j] = max(dp[j], dp[j - w] + v);
//             }
//         }
//     }

//     cout << dp[T] << "\n";

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    if (!(cin >> n >> T)) return 0;

    // dp[i][j] 表示考虑前 i 种物品，容量为 j 时的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int x, w, v;
        cin >> x >> w >> v; // x: 数量上限, w: 重量, v: 价值

        for (int j = 0; j <= T; ++j) {
            // // 基础情况：k = 0，即一件当前物品都不拿，继承上一层的价值
            // dp[i][j] = dp[i - 1][j];

            // // 尝试拿 k 件 (k >= 1)
            // for (int k = 1; k <= x && k * w <= j; ++k) {
            //     dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w] + k * v);
            // }  这里的max里的dpij 就是之前k-1的最好价值
             // k 从 0 开始，包含“不拿当前物品”的情况
            for (int k = 0; k <= x && k * w <= j; k++) {

                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - k * w] + k * v
                );

            }
        }
    }

    cout << dp[n][T] << endl;
    return 0;
}