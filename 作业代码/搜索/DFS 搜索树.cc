#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
vector<int> adj[N]; // 邻接表存树

// u: 当前访问的节点, from: u 的父节点
void dfs(int u, int from) {
    // 1. 【前序位置】
    cout << "访问节点: " << u << "\n";

    // 2. 遍历 u 的所有邻居
    for (int v : adj[u]) {
        if (v == from) continue; // 关键：如果是亲爹，别回头，直接跳过！
        
        // 3. 递归向下
        dfs(v, u); // 此时 u 变成了 v 的 from
    }
}

int main() {
    // 提升输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; // 读入节点总数

    // 树有 n 个节点，必然有 n - 1 条边
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // 读入的是无向边，两边都要加到邻接表里
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "--- 开始 DFS 遍历 ---" << "\n";
    
    // 从根节点 1 开始遍历，由于 1 没有父节点，from 填 -1 或者 0 都可以
    dfs(1, -1); 

    return 0;
}
// 5
// 1 2
// 1 3
// 3 4
// 3 5