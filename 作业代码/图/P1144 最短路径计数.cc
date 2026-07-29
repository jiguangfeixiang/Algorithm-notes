#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 100003;
const int INF = 1e9;

int main() {
    // 优化 I/O 速度，防止大数据超时
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 1. 邻接表存图
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue; // 自环对最短路径毫无贡献，可以直接过滤（不过滤也不影响正确性）
        adj[u].push_back(v);
        adj[v].push_back(u);  // 无向图双向建边
    }

    // 2. 辅助数组
    vector<int> dist(n + 1, INF); // 距离数组，初始化为无穷大
    vector<int> cnt(n + 1, 0);    // 方案数数组，初始化为 0
    queue<int> q;

    // 起点初始化
    dist[1] = 0;
    cnt[1] = 1;
    q.push(1);

    // 3. BFS 状态转移
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // 情况 1：第一次到达点 v，更新最短路并入队
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } 
            // 情况 2：找到另一条等长的最短路，累加方案数，不重复入队
            else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }

    // 4. 按要求输出 1 到 N 每个点的最短路条数
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << "\n";
    }

    return 0;
}