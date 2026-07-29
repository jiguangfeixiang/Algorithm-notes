#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    if (!(cin >> n >> x))
        return 0;

    // dp[j] 表示用 j 瓶药能获得的最大经验
    // 注意：结果可能会超出 int 范围，必须用 long long
    vector<long long> dp(x + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        long long lose, win, use;
        cin >> lose >> win >> use;

        // 01 背包逆序循环
        for (int j = x; j >= 0; --j)
        {
            if (j >= use)
            {
                // 药量足够：比较【放弃打赢拿失败经验】与【消耗 use 药量拿胜利经验】
                dp[j] = max(dp[j] + lose, dp[j - use] + win);
            }
            else
            {
                // 药量不足：只能拿失败经验
                dp[j] = dp[j] + lose;
            }
        }
    }

    // 题目要求输出 5 倍经验
    cout << dp[x] * 5 << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 题目最大数据范围：N <= 1000, X <= 1000
long long dp[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    if (!(cin >> n >> x)) return 0;

    // 为了让代码逻辑与公式完全一致，这里从下标 1 开始存储物品
    for (int i = 1; i <= n; ++i) {
        long long lose, win, use;
        cin >> lose >> win >> use;

        // 在二维 DP 中，j 正序或倒序循环均可
        for (int j = 0; j <= x; ++j) {
            if (j >= use) {
                // 药量足够：比较【不打赢拿失败经验】与【消耗 use 药量打赢】
                dp[i][j] = max(dp[i - 1][j] + lose, dp[i - 1][j - use] + win);
            } else {
                // 药量不足：只能拿失败经验
                dp[i][j] = dp[i - 1][j] + lose;
            }
        }
    }

    // 最终答案为：考虑完 n 个好友、拥有 x 瓶药时的最大经验的 5 倍
    cout << dp[n][x] * 5 << "\n";

    return 0;
}