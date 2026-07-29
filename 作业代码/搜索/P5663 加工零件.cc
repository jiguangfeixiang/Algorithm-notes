#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // 用一个很大的数表示不可达

int main() {
    // 优化输入输出流速度，由于 q 高达 10^5，不加此优化极易超时
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // 邻接表建图
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // d[u][0] 表示从 1 到 u 的最短偶数距离
    // d[u][1] 表示从 1 到 u 的最短奇数距离
    vector<vector<int>> d(n + 1, vector<int>(2, INF));

    // BFS 队列，存储当前节点 u
    queue<int> que;

    // 初始状态：从 1 号点出发，到自身的偶数距离为 0
    d[1][0] = 0;
    que.push(1);

    // 跑一遍双状态 BFS
    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v : adj[u]) {
            // 从 u 走到 v 步数加 1，奇偶性发生改变

            // 1. 尝试更新 v 的偶数距离（由 u 的奇数距离 + 1 得到）
            if (d[u][1] + 1 < d[v][0]) {
                d[v][0] = d[u][1] + 1;
                que.push(v);
            }
            // 2. 尝试更新 v 的奇数距离（由 u 的偶数距离 + 1 得到）
            if (d[u][0] + 1 < d[v][1]) {
                d[v][1] = d[u][0] + 1;
                que.push(v);
            }
        }
    }

    // 处理 q 个工单
    while (q--) {
        int a, L;
        cin >> a >> L;

        // 特判：如果 1 号点是孤立点，谁也帮不了
        if (adj[1].empty()) {
            cout << "No\n";
            continue;
        }

        // 根据 L 的奇偶性进行判断
        int opt = L % 2; 
        if (L >= d[a][opt]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}