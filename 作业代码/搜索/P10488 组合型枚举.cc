#include <iostream>
#include <vector>

using namespace std;

int n, m;
int path[30]; // 用数组保存当前选中的组合，path[1..m]

// pos: 当前正在确定第 pos 个数字
// start: 当前位置可选择的最小数字
void dfs(int pos, int start) {
    // 递归边界：成功填满 m 个位置
    if (pos > m) {
        for (int i = 1; i <= m; i++) {
            cout << path[i] << (i == m ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // 枚举当前 pos 位置可以填入的数字 i
    for (int i = start; i <= n; i++) {
        // 剪枝：剩余可选数字个数 (n - i + 1) 小于 剩余所需数字个数 (m - pos + 1)
        if (n - i + 1 < m - pos + 1) {
            break;
        }

        path[pos] = i;        // 填入第 pos 位
        dfs(pos + 1, i + 1);  // 递归填第 pos + 1 位，下一位的起始选数必须是 i + 1
        // 注意：此处覆盖写 path[pos]，无需显示的 pop/回溯清除操作
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    if (m == 0) return 0; // m = 0 时不输出任何组合

    dfs(1, 1); // 从第 1 个位置开始填，可选数字从 1 开始

    return 0;
}