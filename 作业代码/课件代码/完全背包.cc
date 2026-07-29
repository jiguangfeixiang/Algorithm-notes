#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 标记无效/无法恰好装满的状态

int main()
{
    // 提高 IO 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, V;
    if (!(cin >> n >> V))
        return 0;

    // 物品信息 (1-indexed)
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i] >> w[i];
    }

    // 1. 第一问：不要求装满（全部初始化为 0）
    vector<vector<int>> dp1(n + 1, vector<int>(V + 1, 0));

    // 2. 第二问：要求恰好装满（dp2[0][0] = 0，其余初始化为 -INF）
    vector<vector<int>> dp2(n + 1, vector<int>(V + 1, -INF));
    dp2[0][0] = 0;

    // 填表
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= V; ++j)
        {

            // --- 第一问：不要求装满 ---
            // 情况 A：不选第 i 种物品
            // 情况 B：选第 i 种物品（注意是 dp1[i][j - v[i]]，看本行左侧）
            if (j >= v[i])
            {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - v[i]] + w[i]);
            }
            else
            {
                dp1[i][j] = dp1[i - 1][j];
            }

            // --- 第二问：要求恰好装满 ---
            // 情况 A：不选第 i 种物品
            // 情况 B：选第 i 种物品（要求前置状态 dp2[i][j - v[i]] 是有效的）
            if (j >= v[i] && dp2[i][j - v[i]] != -INF)
            {
                dp2[i][j] = max(dp2[i][j] = dp2[i - 1][j], dp2[i][j - v[i]] + w[i]);
            }
            else
            {
                dp2[i][j] = dp2[i - 1][j];
            }
        }
    }

    // 第一问答案
    cout << dp1[n][V] << "\n";

    // 第二问答案（若仍小于 0，说明无解输出 0）
    if (dp2[n][V] < 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << dp2[n][V] << "\n";
    }

    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int INF = 1e9; // 标记无效/无法恰好装满的状态

// int main() {
//     // 优化 IO 速度
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, V;
//     if (!(cin >> n >> V)) return 0;

//     // dp1: 第一问，不要求装满（初始化为 0）
//     vector<int> dp1(V + 1, 0);

//     // dp2: 第二问，要求恰好装满（dp2[0] = 0，其余初始化为 -INF）
//     vector<int> dp2(V + 1, -INF);
//     dp2[0] = 0;

//     for (int i = 0; i < n; ++i) {
//         int v, w;
//         cin >> v >> w;

//         // 完全背包核心：容量正序遍历 (v -> V)
//         for (int j = v; j <= V; ++j) {
//             // 1. 第一问直接更新
//             dp1[j] = max(dp1[j], dp1[j - v] + w);

//             // 2. 第二问：仅当 dp2[j - v] 为有效状态时更新
//             if (dp2[j - v] != -INF) {
//                 dp2[j] = max(dp2[j], dp2[j - v] + w);
//             }
//         }
//     }

//     // 第一问答案
//     cout << dp1[V] << "\n";

//     // 第二问答案（若小于 0 说明无法恰好装满，输出 0）
//     if (dp2[V] < 0) {
//         cout << 0 << "\n";
//     } else {
//         cout << dp2[V] << "\n";
//     }

//     return 0;
// }