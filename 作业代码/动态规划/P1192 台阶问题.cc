#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100003;

int main() {
    // 优化输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    // dp[i] 表示到达第 i 级台阶的方法数
    vector<int> dp(n + 1, 0);

    // 初始状态：站在第 0 级台阶有 1 种方法
    dp[0] = 1;

    // 递推计算每一级台阶
    for (int i = 1; i <= n; ++i) {
        // 向上迈 1 到 K 级
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            } else {
                break; // 如果 i - j < 0，再往后减肯定也 < 0，直接跳出内层循环
            }
        }
    }

    // 输出到达第 N 级台阶的方法数
    cout << dp[n] << "\n";

    return 0;
}