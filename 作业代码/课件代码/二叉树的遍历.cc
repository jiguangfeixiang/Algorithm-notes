#include <iostream>

using namespace std;

// N 最大是 10^6，数组开大一点点防止越界
const int MAXN = 1000005;

// 静态数组存储二叉树
// lchild[i] 表示节点 i 的左孩子，rchild[i] 表示节点 i 的右孩子
int lchild[MAXN];
int rchild[MAXN];

// 顺手写一个先序遍历（Pre-order），用于验证建树是否成功
void preorder(int u) {
    if (u == 0) return; // 0 表示空节点
    
    cout << u << " ";     // 访问当前节点
    preorder(lchild[u]);  // 递归左子树
    preorder(rchild[u]);  // 递归右子树
}

int main() {
    // 核心优化：极大加速 cin 和 cout 的执行效率，防止 10^6 数据量超时
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // 循环读入每个节点的左右子节点
    for (int i = 1; i <= n; ++i) {
        cin >> lchild[i] >> rchild[i];
    }

    // 题目指定 1 号节点为根节点
    int root = 1;

    // 此时树已经建好，可以根据题目后续要求进行操作
    // 比如这里打印一下先序遍历结果
    preorder(root);

    return 0;
}