
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 快速输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    vector<long long> dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i] = a[i]; // 初始化：单独成队时，最大和就是自身
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // 如果严格上升，尝试把 a[i] 接到 a[j] 后面
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans, dp[i]); // 维护全局最大和
    }

    cout << ans << "\n";

    return 0;
}