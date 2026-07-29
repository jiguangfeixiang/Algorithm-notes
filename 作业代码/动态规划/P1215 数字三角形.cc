#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1005][1005];
int dp[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    if (!(cin >> r)) return 0;

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    // --- 1. 初始化起点 ---
    dp[1][1] = a[1][1];

    // --- 2. 自顶向下递推 ---
    for (int i = 2; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) {
                // 最左边一列：只能从正上方 (i-1, 1) 走过来
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == i) {
                // 最右边一列：只能从左上方 (i-1, j-1) 走过来
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                // 中间普通格子：两个来源取 max
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            }
        }
    }

    // --- 3. 统计最后一行的最大值 ---
    int ans = 0;
    for (int j = 1; j <= r; ++j) {
        ans = max(ans, dp[r][j]);
    }

    cout << ans << "\n";

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// int a[1005][1005];
// int dp[1005][1005];

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int r;
//     if (!(cin >> r)) return 0;

//     for (int i = 1; i <= r; ++i) {
//         for (int j = 1; j <= i; ++j) {
//             cin >> a[i][j];
//         }
//     }

//     // --- 1. 哨兵初始化：全盘填 -1，充当防污染的安全墙 ---
//     memset(dp, -1, sizeof(dp));

//     // --- 2. 激活唯一发车起点 ---
//     dp[1][1] = a[1][1];

//     // --- 3. 统一方程递推 ---
//     for (int i = 2; i <= r; ++i) {
//         for (int j = 1; j <= i; ++j) {
//             // 越界的位置值是 -1，会被 max 自然过滤，无需任何 if-else 判断！
//             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
//         }
//     }

//     // --- 4. 统计最后一行的最大值 ---
//     int ans = 0;
//     for (int j = 1; j <= r; ++j) {
//         ans = max(ans, dp[r][j]);
//     }

//     cout << ans << "\n";

//     return 0;
// }