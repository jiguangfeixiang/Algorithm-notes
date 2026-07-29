#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100005;
vector<int> adj[N];   // 邻接表：adj[u] 存放所有与 u 相连的节点
bool visited[N];      // 标记数组：防止遍历时走回头路导致死循环

// ==================== 2. 图的遍历 ====================

// ① DFS（深度优先搜索）：一条道走到黑，不撞南墙不回头
void dfs(int u) {
    visited[u] = true;
    cout << u << " "; // 打印当前访问的节点

    for (int v : adj[u]) {
        if (!visited[v]) { // 如果邻居没被访问过，就揪住它继续往下钻
            dfs(v);
        }
    }
}

// ② BFS（广度优先搜索）：层层递进，像水波纹一样向外扩散
void bfs(int start) {
    queue<int> q;
    
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // 打印当前弹出的节点

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true; // 只要入队，就要立刻标记，防止重复入队
                q.push(v);
            }
        }
    }
}

// 重置标记数组（因为跑完 DFS 数组全黑了，跑 BFS 前要洗白）
void reset_visited(int n) {
    for (int i = 1; i <= n; ++i) visited[i] = false;
}

// ==================== 1. 图的建立 ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n 个点，m 条边
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // 无向图建图：两边互相加对方为邻居
        adj[u].push_back(v);
        adj[v].push_back(u); 
        
        // 💡 如果是有向图(u -> v)，只需要保留上面那一句 adj[u].push_back(v) 即可
    }

    cout << "--- DFS 遍历结果 ---" << "\n";
    reset_visited(n);
    dfs(1); // 从 1 号点开始深度遍历
    cout << "\n";

    cout << "--- BFS 遍历结果 ---" << "\n";
    reset_visited(n);
    bfs(1); // 从 1 号点开始广度遍历
    cout << "\n";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int N = 100005; // 节点数上限

// 1. 无权图（只需要存邻居节点）
vector<int> adj[N];

// 2. 带权图（存结构体或者 pair <邻居节点, 边权>）
struct Edge {
    int to;     // 目标节点
    int weight; // 边权
};
vector<Edge> graph[N];

int main() {
    int n, m; // n个点，m条边
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // 输入一条从 u 到 v，权重为 w 的边

        // 无向图：两边都要加；有向图：只加单向
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // 如果是有向图，删掉这句
    }

    // 遍历节点 u 的所有邻居
    int u = 1;
    for (auto edge : graph[u]) {
        cout << "到节点 " << edge.to << " 的边权为 " << edge.weight << endl;
    }

    return 0;
}