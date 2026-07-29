// 查找文献
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
vector<int> G[100005];
vector<bool> vis_dfs(100005, false);
void dfs(int start){
    vis_dfs[start] = true;
    cout << start << " ";
    for (int i = 0; i < G[start].size(); i++)
    {
        int next_node = G[start][i];
        if (!vis_dfs[next_node])
        {
            dfs(next_node);
        }
        
    }
    
}
vector<int> vis_bfs(100005, false);
void bfs(int start){
    queue<int> q;
    q.push(start);
    vis_bfs[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current <<" ";
        for (int i = 0; i < G[current].size(); i++)
        {
            int next_node = G[current][i];
            if (!vis_bfs[next_node])
            {
                vis_bfs[next_node] = true;
                q.push(next_node);
            }
            
        }
        
    }
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 1; i <=n; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
    dfs(1);
    cout << endl;
    bfs(1);
    cout << endl;

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// // 图的邻接表表示法：g[u] 存储从节点 u 出发能到达的所有节点
// vector<vector<int>> g;

// // dist[i]：起点 1 到节点 i 的最短步数
// // parent[i]：路径追溯数组，记录节点 i 是从哪一个节点跳转过来的
// vector<int> dist;
// vector<int> parent;

// // 1. 利用 BFS 求解无权图的最短路径
// void bfs_shortest_path(int start, int n) {
//     // 初始化数组大小及默认值（-1 表示未访问/无法到达）
//     dist.assign(n + 1, -1);
//     parent.assign(n + 1, -1);

//     queue<int> q;

//     // 起点初始化
//     dist[start] = 0;
//     q.push(start);

//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         // 遍历 u 的所有邻居
//         for (int v : g[u]) {
//             // 如果 v 尚未被访问，则当前路径必然是到达 v 的最短路径
//             if (dist[v] == -1) {
//                 dist[v] = dist[u] + 1; // 距离加 1
//                 parent[v] = u;         // 记录前驱节点为 u
//                 q.push(v);             // 邻居入队
//             }
//         }
//     }
// }

// // 2. 根据 parent 数组逆向还原并打印从起点 start 到目标点 target 的路径
// void print_path(int start, int target) {
//     if (dist[target] == -1) {
//         cout << "无法从文章 " << start << " 到达文章 " << target << "\n";
//         return;
//     }

//     // 利用 vector 收集从 target 一路追溯回 start 的节点
//     vector<int> path;
//     for (int curr = target; curr != -1; curr = parent[curr]) {
//         path.push_back(curr);
//     }

//     // 因为是倒序收集的（终点 -> 起点），所以需要反转
//     reverse(path.begin(), path.end());

//     // 格式化输出路径轨迹
//     cout << "文章 " << start << " -> 文章 " << target << " 的最短路径为：";
//     for (size_t i = 0; i < path.size(); ++i) {
//         cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
//     }
//     cout << " (共 " << dist[target] << " 步)\n";
// }

// int main() {
//     // 优化标准输入输出流，提升大数据量下的 I/O 速度
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     if (!(cin >> n >> m)) return 0;

//     // 动态调整邻接表大小，1-indexed（节点编号 1~n）
//     g.resize(n + 1);

//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v); // 有向边 u -> v
//     }

//     // 按照题目要求：“如果有多篇文章可选，先看编号较小的那篇”
//     // 对每个节点的出边邻居列表进行升序排序
//     for (int i = 1; i <= n; ++i) {
//         sort(g[i].begin(), g[i].end());
//     }

//     int start_node = 1;

//     // 执行 BFS 计算起点为 1 的最短路径
//     bfs_shortest_path(start_node, n);

//     cout << "================ 最短路径计算结果 ================\n";

//     // 示例：输出起点 1 到所有节点的步数与具体轨迹
//     for (int i = 1; i <= n; ++i) {
//         print_path(start_node, i);
//     }

//     return 0;
// }