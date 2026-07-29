#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    if (!(cin >> n >> r)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    // 1. 贪心：将打水时间从小到大排序
    sort(t.begin(), t.end());

    long long total_time = 0;

    // 2. 依次计算每个人对总时间的贡献
    // 排序后第 i 个人（从 0 开始），后面在他所在水龙头排队的人数（含自己）为 (n - i + r - 1) / r
    for (int i = 0; i < n; ++i) {
        // (n - i - 1) / r 表示在第 i 个人之后，同水龙头排队的剩余人数
        int remaining_in_line = (n - 1 - i) / r + 1; 
        total_time += (long long)t[i] * remaining_in_line;
    }

    cout << total_time << "\n";

    return 0;
}