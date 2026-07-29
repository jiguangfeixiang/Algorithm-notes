#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 全局变量定义
const int N = 100005;      // 最大节点数
const int INF = 1e9;       // 用一个很大的数表示不可达
vector<int> adj[N];        // 邻接表存图：adj[u] 里面存 u 的所有邻居
bool visited[N];           // 标记数组：visited[u] = true 表示 u 已经被访问过
int dist[N];               // 距离数组：dist[u] 表示从起点到节点 u 的最短步数

// ==================== 核心 BFS 函数 ====================
void bfs(int start, int n) {
    // 1. 初始化数组：将所有点的距离设为无穷大，标记设为未访问
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }

    // 2. 声明 BFS 队列
    queue<int> q;

    // 3. 起点初始化：起点入队，打上标记，起点到自己的距离为 0
    q.push(start);
    visited[start] = true; // 【铁律】只要入队，必须当场标记！
    dist[start] = 0;

    // 4. 开始队列循环
    while (!q.empty()) {
        int u = q.front(); // 取出队头节点
        q.pop();           // 弹出队头

        // 5. 遍历当前节点 u 的所有邻居 v
        for (int v : adj[u]) {
            // 如果邻居 v 没有被访问过
            if (!visited[v]) {
                visited[v] = true;       // 立刻锁死，防止别的点重复把它送入队列
                dist[v] = dist[u] + 1;   // 从 u 走到 v，步数在 u 的基础上加 1
                q.push(v);               // 邻居入队，等待下一轮扩散
            }
        }
    }
}

// ==================== 主函数 ====================
int main() {
    // 提升输入输出流效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n 个点，m 条边
    if (!(cin >> n >> m)) return 0;

    // 读入 m 条双向边建图
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // 假设我们从 1 号节点出发跑 BFS
    int start_node = 1;
    bfs(start_node, n);

    // ==================== 输出结果 ====================
    cout << "--- 从节点 " << start_node << " 出发的最短步数统计 ---\n";
    for (int i = 1; i <= n; ++i) {
        cout << "到节点 " << i << " : ";
        if (dist[i] == INF) {
            cout << "不可达 (Unreachable)\n";
        } else {
            cout << dist[i] << " 步\n";
        }
    }

    return 0;
}
// 树的操作

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// const int N = 100005;
// vector<int> adj[N]; // 邻接表存树

// // 结构体：存储节点本身以及它是从哪个父节点走过来的（防回头）
// struct NodeState {
//     int u;    // 当前节点
//     int from; // 父节点
// };

// void bfs_tree(int root) {
//     // 声明存储结构体的队列
//     queue<NodeState> q;

//     // 根节点入队，它没有父节点，填 -1 或者是 0
//     q.push({root, -1});

//     int level = 1; // 记录当前是第几层

//     while (!q.empty()) {
//         // 【核心神技】当前队列里的元素个数，刚好就是当前这一层的节点总数！
//         int level_size = q.size(); 
        
//         cout << "第 " << level << " 层: ";

//         // 一口气把当前这一层的所有节点全部弹出并处理完
//         for (int i = 0; i < level_size; ++i) {
//             NodeState curr = q.front();
//             q.pop();

//             int u = curr.u;
//             int from = curr.from;

//             cout << u << " "; // 访问当前节点

//             // 遍历当前节点的所有邻居（即孩子和亲爹）
//             for (int v : adj[u]) {
//                 if (v == from) continue; // 关键：如果是亲爹，别回头，直接跳过！
                
//                 q.push({v, u}); // 孩子入队，同时把当前节点 u 作为它的 from 传过去
//             }
//         }
//         cout << "\n";
//         level++; // 这一层全弹光了，进入下一层
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n; // 读入节点总数

//     // 树有 n 个节点，必然有 n - 1 条边
//     for (int i = 0; i < n - 1; ++i) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); // 当作无向边存入
//     }

//     cout << "--- 开始树的 BFS 层序遍历 ---\n";
//     bfs_tree(1); // 假设从 1 号节点作为根开始遍历

//     return 0;
// }