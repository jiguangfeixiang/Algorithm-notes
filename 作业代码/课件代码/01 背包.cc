#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f; // 用一个足够大的数代表负无穷

int main() {

    int n, V;
    if (!(cin >> n >> V)) return 0;

    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    // ================= 方案 1：不要求恰好装满 (二维) =================
    // dp1[i][j] 表示前 i 个物品，容量上限为 j 时的最大价值
    vector<vector<int>> dp1(n + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j < v[i]) {
                // 容量放不下第 i 件物品，继承上一行的结果
                dp1[i][j] = dp1[i - 1][j];
            } else {
                // 不放第 i 件 vs 放第 i 件，取最大值
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    // ================= 方案 2：要求恰好装满 (二维) =================
    // dp2[i][j] 表示前 i 个物品，容量恰好为 j 时的最大价值
    vector<vector<int>> dp2(n + 1, vector<int>(V + 1, -INF));
    dp2[0][0] = 0; // 0 个物品凑出容量 0 是唯一合法的起始状态

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; ++j) {
            // 先默认不选第 i 件物品
            dp2[i][j] = dp2[i - 1][j];

            // 如果容量够放，且上一行的 dp2[i-1][j - v[i]] 是合法状态
            if (j >= v[i] && dp2[i - 1][j - v[i]] != -INF) {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    // ================= 输出答案 =================
    // 方案 1 答案：在前 n 个物品中，不超过容量 V 的最大价值
    cout << dp1[n][V] << "\n";

    // 方案 2 答案：如果不等于 -INF（且大于 0），输出 dp2[n][V]，否则输出 0
    if (dp2[n][V] < 0) {
        cout << 0 << "\n";
    } else {
        cout << dp2[n][V] << "\n";
    }

    return 0;
}
// }
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int INF = 0x3f3f3f3f;

// int main() {
//     // 提高输入输出效率
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, V;
//     if (!(cin >> n >> V)) return 0;

//     vector<int> v(n), w(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> v[i] >> w[i];
//     }

//     // ================= 方案 1：不要求恰好装满 (一维滚动数组) =================
//     vector<int> dp1(V + 1, 0); // 初始全 0

//     for (int i = 0; i < n; ++i) {
//         // 01背包核心：容量从大到小倒序遍历
//         for (int j = V; j >= v[i]; --j) {
//             dp1[j] = max(dp1[j], dp1[j - v[i]] + w[i]);
//         }
//     }

//     // ================= 方案 2：要求恰好装满 (一维滚动数组) =================
//     vector<int> dp2(V + 1, -INF); // 除了 0 位置，其余全是 -INF
//     dp2[0] = 0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = V; j >= v[i]; --j) {
//             // 只有当转移的前置状态 dp2[j - v[i]] 合法时，才进行更新
//             if (dp2[j - v[i]] != -INF) {
//                 dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
//             }
//         }
//     }

//     // ================= 输出答案 =================
//     cout << dp1[V] << "\n";

//     if (dp2[V] < 0) {
//         cout << 0 << "\n";
//     } else {
//         cout << dp2[V] << "\n";
//     }

//     return 0;
// }