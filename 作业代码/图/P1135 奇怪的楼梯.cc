#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

// dist[i] 记录从 A 楼到第 i 层楼的最少按键次数
vector<int> dist(100005, INF);
// visited[i] 标记第 i 层楼是否已经去过
vector<bool> visited(100005, false);
vector<int> k(100005);
int n, a, b;

void bfs(int start, int end)
{

    queue<int> q;

    // 起点初始化
    q.push(start);
    visited[start] = true; // 【铁律】入队即锁死
    dist[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // 如果已经到了目标 B 楼，由于 BFS 的层序特性，这一定是最少次数，直接退出
        if (current == end)
            break;

        // 决策 1：尝试向上按按钮
        int next_up = current + k[current];
        if (next_up <= n && !visited[next_up])
        {
            visited[next_up] = true;
            dist[next_up] = dist[current] + 1;
            q.push(next_up);
        }

        // 决策 2：尝试向下按按钮
        int next_down = current - k[current];
        if (next_down >= 1 && !visited[next_down])
        {
            visited[next_down] = true;
            dist[next_down] = dist[current] + 1;
            q.push(next_down);
        }
    }
}
int main()
{
    cin >> n >> a >> b;

    // 读入每一层楼的数字 K_i，编号从 1 到 n
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
    }
    bfs(a, b);

    // 输出答案
    if (dist[b] == INF)
    {
        cout << -1 << "\n"; // 无法到达
    }
    else
    {
        cout << dist[b] << "\n";
    }

    return 0;
}