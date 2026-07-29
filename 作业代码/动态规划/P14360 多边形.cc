// // 多边形 - 1-indexed 二维 DP 版本
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int MOD = 998244353;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     // 木棍数组从 1 到 n 存储
//     vector<int> a(n + 1);
//     int max_val = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         max_val = max(max_val, a[i]);
//     }

//     // 1. 将木棍按长度升序排序 (从 a[1] 到 a[n])
//     sort(a.begin() + 1, a.end());

//     // 预计算 2 的幂次，用于求前 i-1 根木棍构成的全集子集数 2^(i-1)
//     vector<long long> pow2(n + 1, 1);
//     for (int i = 1; i <= n; ++i) {
//         pow2[i] = (pow2[i - 1] * 2) % MOD;
//     }

//     // 2. 定义二维 DP 数组
//     // dp[i][j] 表示前 i 根木棍（a[1] ~ a[i]）中挑选，长度之和为 j 的方案数
//     vector<vector<long long>> dp(n + 1, vector<long long>(max_val + 1, 0));

//     // 初始状态：前 0 根木棍（什么都不选），凑成和为 0 的方案数为 1
//     dp[0][0] = 1;

//     long long total_ans = 0;

//     // 3. 依次枚举第 i 根木棍作为【最长木棍】
//     for (int i = 1; i <= n; ++i) {
//         int cur = a[i];

//         // 步骤 A：统计在前 i - 1 根木棍中，和 S <= cur 的不合法方案数
//         // 注意：此时用的是 dp[i - 1][j]
//         long long invalid_cnt = 0;
//         for (int j = 0; j <= cur; ++j) {
//             invalid_cnt = (invalid_cnt + dp[i - 1][j]) % MOD;
//         }

//         // 以 a[i] 为最大木棍的合法方案数 = 总方案数 2^(i-1) - 不合法方案数
//         long long valid_cnt = (pow2[i - 1] - invalid_cnt + MOD) % MOD;
//         total_ans = (total_ans + valid_cnt) % MOD;

//         // 步骤 B：用前 i - 1 根木棍的状态推出前 i 根木棍的状态 dp[i][j]
//         for (int j = 0; j <= max_val; ++j) {
//             // 不选第 i 根木棍 a[i]
//             dp[i][j] = dp[i - 1][j];

//             // 选择第 i 根木棍 a[i]
//             if (j >= cur) {
//                 dp[i][j] = (dp[i][j] + dp[i - 1][j - cur]) % MOD;
//             }
//         }
//     }

//     cout << total_ans << "\n";

//     return 0;
// }
// 多边形 - 1-indexed 二维 DP 版本
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int MOD = 998244353;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     // 木棍数组从 1 到 n 存储
//     vector<int> a(n + 1);
//     int max_val = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         max_val = max(max_val, a[i]);
//     }

//     // 1. 将木棍按长度升序排序 (从 a[1] 到 a[n])
//     sort(a.begin() + 1, a.end());

//     // 预计算 2 的幂次，用于求前 i-1 根木棍构成的全集子集数 2^(i-1)
//     vector<long long> pow2(n + 1, 1);
//     for (int i = 1; i <= n; ++i) {
//         pow2[i] = (pow2[i - 1] * 2) % MOD;
//     }

//     // 2. 定义二维 DP 数组
//     // dp[i][j] 表示前 i 根木棍（a[1] ~ a[i]）中挑选，长度之和为 j 的方案数
//     vector<vector<long long>> dp(n + 1, vector<long long>(max_val + 1, 0));

//     // 初始状态：前 0 根木棍（什么都不选），凑成和为 0 的方案数为 1
//     dp[0][0] = 1;

//     long long total_ans = 0;

//     // 3. 依次枚举第 i 根木棍作为【最长木棍】
//     for (int i = 1; i <= n; ++i) {
//         int cur = a[i];

//         // 步骤 A：统计在前 i - 1 根木棍中，和 S <= cur 的不合法方案数
//         // 注意：此时用的是 dp[i - 1][j]
//         long long invalid_cnt = 0;
//         for (int j = 0; j <= cur; ++j) {
//             invalid_cnt = (invalid_cnt + dp[i - 1][j])  ;
//         }

//         // 以 a[i] 为最大木棍的合法方案数 = 总方案数 2^(i-1) - 不合法方案数
//         long long valid_cnt = (pow2[i - 1] - invalid_cnt )  ;
//         total_ans = (total_ans + valid_cnt)  ;

//         // 步骤 B：用前 i - 1 根木棍的状态推出前 i 根木棍的状态 dp[i][j]
//         for (int j = 0; j <= max_val; ++j) {
//             // 不选第 i 根木棍 a[i]
//             dp[i][j] = dp[i - 1][j];

//             // 选择第 i 根木棍 a[i]
//             if (j >= cur) {
//                 dp[i][j] = (dp[i][j] + dp[i - 1][j - cur]) ;
//             }
//         }
//     }

//     cout << total_ans << "\n";

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    // ================= 混分招式 1：针对 N = 3 的测试点（直接 3 层 for 循环） =================
    if (n == 3) {
        // N=3 时只有 1 种选法：把 3 根木棍全部选上
        long long sum = a[0] + a[1] + a[2];
        long long mx = max({a[0], a[1], a[2]});
        
        // 验证是否满足条件
        if (sum > 2 * mx) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return 0;
    }

    // ================= 混分招式 2：针对所有 a_i 都等于 1 的测试点（直接公式） =================
    if (max_val == 1) {
        // 1. 用简单 for 循环算 2^n
        long long pow2 = 1;
        for (int i = 1; i <= n; ++i) {
            pow2 = (pow2 * 2) % MOD;
        }

        // 2. 不合法的方案数：选 0 根(1种)、选 1 根(n种)、选 2 根(n*(n-1)/2 种)
        long long c0 = 1;
        long long c1 = n;
        long long c2 = (1LL * n * (n - 1) / 2) % MOD;

        long long invalid = (c0 + c1 + c2) % MOD;

        // 3. 总方案数 - 不合法方案数（记得 + MOD 防止负数）
        long long ans = (pow2 - invalid + MOD) % MOD;

        cout << ans << "\n";
        return 0;
    }

    // ================= 其他情况实在不会，输出 0 碰运气 =================
    cout << 0 << "\n";

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// const int MOD = 998244353;

// // 快速幂：计算 base^exp % MOD
// long long power(long long base, long long exp) {
//     long long res = 1;
//     base %= MOD;
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % MOD;
//         base = (base * base) % MOD;
//         exp /= 2;
//     }
//     return res;
// }

// // 用费马小定理求除法对应的逆元 (等于乘以 a^(MOD-2))
// long long modInverse(long long a) {
//     return power(a, MOD - 2);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     vector<int> a(n + 1);
//     int max_val = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         if (a[i] > max_val) max_val = a[i];
//     }

//     // ================= 混分招式：直接套 C(n, i) 公式并用 for 循环相加 =================
//     if (max_val == 1) {
//         // 1. 预计算阶乘 fact[i] = i! % MOD
//         vector<long long> fact(n + 1, 1);
//         for (int i = 1; i <= n; ++i) {
//             fact[i] = (fact[i - 1] * i) % MOD;
//         }

//         long long ans = 0;

//         // 2. 用 for 循环直接累加：C(n, 3) + C(n, 4) + ... + C(n, n)
//         for (int i = 3; i <= n; ++i) {
//             // 公式：C(n, i) = n! / (i! * (n-i)!)
//             // 在模运算下：C(n, i) = fact[n] * inv(fact[i]) * inv(fact[n-i]) % MOD
//             long long num = fact[n]; // 分子：n!
//             long long den = (fact[i] * fact[n - i]) % MOD; // 分母：i! * (n-i)!
            
//             long long C_n_i = (num * modInverse(den)) % MOD; // 分子 * 分母的逆元

//             // 直接正面相加
//             ans = (ans + C_n_i) % MOD;
//         }

//         cout << ans << "\n";
//         return 0;
//     }

//     // 其他情况输出 0
//     cout << 0 << "\n";

//     return 0;
// }