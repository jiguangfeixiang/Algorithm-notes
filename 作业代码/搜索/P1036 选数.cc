#include <iostream>
#include <vector>

using namespace std;

int n, k;
int a[25];
int ans = 0;
int sum = 0;
// 素数（质数）判定函数
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// DFS 状态定义：
// pos: 当前正在确定选第 pos 个数 (1 <= pos <= k)
// start: 当前可以从数组 a 中的 start 位置开始选 (1 <= start <= n)
// sum: 当前已选择数字的和
void dfs(int pos, int start) {
    // 递归边界：已成功选满 k 个数
    if (pos > k) {
        if (isPrime(sum)) {
            ans++;
        }
        return;
    }

    // 枚举当前可以选择的元素下标 i
    for (int i = start; i <= n; i++) {
        // 剪枝：如果剩下的元素个数不足以凑够 k 个数，直接结束循环
        // 剩余可选元素个数: n - i + 1
        // 还需选择元素个数: k - pos + 1
        if (n - i + 1 < k - pos + 1) {
            break;
        }

        // 选择 a[i]，递归进入下一个位置
        sum += a[i];
        dfs(pos + 1, i + 1);
        sum -= a[i];
    }
}

int main() {
    // 优化 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 从第 1 个数开始选择，原数组从下标 1 开始选，当前和为 0
    dfs(1, 1);

    cout << ans << "\n";

    return 0;
}