#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    int ans = 0;
    long long current_xor = 0;

    // key: 前缀异或和, value: 该异或和对应的数组下标 (从 1 开始记)
    unordered_map<long long, int> has_prefix;
    
    // 初始化：P_0 = 0 出现在下标 0 处
    has_prefix[0] = 0;

    for (int i = 1; i <= n; ++i) { // 这里为了方便，让 i 从 1 到 n
        long long a;
        cin >> a;
        current_xor ^= a; // 当前 P_i

        long long target = current_xor ^ k; // 寻找 P_{l-1}

        if (has_prefix.count(target)) {
            // 找到了对应的左端点下标 left_idx = has_prefix[target]
            // 这意味着区间 [left_idx + 1, i] 的异或和刚好为 k！
            ans++;

            // 贪心选择：清空哈希表，重置起点为当前下标 i
            has_prefix.clear();
            has_prefix[current_xor] = i; 
        } else {
            // 记录当前前缀异或和出现的下标
            has_prefix[current_xor] = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
// 混分
#include <iostream>
#include <vector>

using namespace std;

int n;
long long k;
vector<long long> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;
    
    a.resize(n + 1);
    bool all_one = true;
    bool all_01 = true;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 1) all_one = false;
        if (a[i] != 0 && a[i] != 1) all_01 = false;
    }

    // ----------------- 特殊性质 A 特判 -----------------
    if (all_one) {
        // if (k == 1) cout << n << "\n";
        if (k == 0) cout << n / 2 << "\n";
        // else cout << 0 << "\n";
        return 0;
    }

    // ----------------- 特殊性质 B 特判 -----------------
    if (all_01) {
        int ans = 0;
        int ones = 0; // 记录连续 1 的个数
        for (int i = 1; i <= n; ++i) {
            if (k == 0) {
                if (a[i] == 0) {
                    ans++;
                } else {
                    ones++;
                    if (ones == 2) {
                        ans++;
                        ones = 0; // 凑够两个 1 抵消为 0
                    }
                }
            } else if (k == 1) {
                if (a[i] == 1) {
                    ans++; // 单个 1 异或和就是 1
                }
            }
        }
        cout << ans << "\n";
        return 0;
    }

    cout << 0 << "\n";

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     long long k;
//     if (!(cin >> n >> k)) return 0;

//     vector<long long> a(n + 1);
//     for (int i = 1; i <= n; ++i) cin >> a[i];

//     // dp[i] 表示前 i 个元素能选出的最大不重叠区间数
//     vector<int> dp(n + 1, 0);

//     for (int i = 1; i <= n; ++i) {
//         // dp[i] = dp[i - 1]; // 默认继承前一个位置的最佳结果
//         long long cur_xor = 0;

//         // 从 i 往左找，寻找离 i 最近的合法左端点 j
//         for (int j = i; j >= 1; --j) {
//             cur_xor ^= a[j];
//             if (cur_xor == k) {
//                 dp[i] = max(dp[i-1], dp[j - 1] + 1);
//                 break; // 贪心：离 i 最近的 j 一定最便宜/给前面留的空间最大
//             }
//         }
//     }

//     cout << dp[n] << "\n";
//     return 0;
// }