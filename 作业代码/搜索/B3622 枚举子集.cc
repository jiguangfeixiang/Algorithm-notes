#include <iostream>
#include <vector>

using namespace std;

int n;
char path[15]; // 用于记录当前选择方案的字符数组

// dfs(u) 表示正在确定第 u 位同学的选择
void dfs(int u) {
    // 递归边界：n 位同学都决定好了，输出结果
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            cout << path[i];
        }
        cout << "\n";
        return;
    }

    // 分支 1：不参加 ('N') -> 字典序较小，先搜索
    path[u] = 'N';
    dfs(u + 1);

    // 分支 2：参加 ('Y')
    path[u] = 'Y';
    dfs(u + 1);
}

int main() {

    if (cin >> n) {
        dfs(1); // 从第 1 位同学开始递归
    }

    return 0;
}
//                      dfs(1)  表示第1个同学选还是不选
//                    /        \
//              'N'  /          \  'Y'
//                  /            \
//              dfs(2)          dfs(2)  第2个同学选或者不选
//              /    \          /    \
//        'N'  /      \ 'Y' 'N'/      \ 'Y'
//            /        \      /        \
//        dfs(3)     dfs(3) dfs(3)    dfs(3)
//        /   \      /   \  /   \     /   \
//       N     Y    N     YN     Y   N     Y
//      NNN   NNY  NYN   NYYYNN YNY YYN   YYY  <-- 输出答案（共 2^3 = 8 种）