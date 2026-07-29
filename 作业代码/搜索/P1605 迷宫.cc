#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int ans = 0; // 记录总方案数

// 迷宫状态数组：true 代表不可通过（可能是障碍，也可能是当前路径已走过）
bool visited[6][6];

// 方向数组：上下左右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    // 1. 递归出口：到达终点
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }

    // 2. 尝试向四个方向移动
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 3. 边界检查与合法性检查（合二为一）
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny])
        {
            // 4. 做出选择（标记已访问）
            visited[nx][ny] = true;

            // 递归深入下一层
            dfs(nx, ny);

            // 5. 回溯（恢复现场）
            visited[nx][ny] = false;
        }
    }
}

int main()
{


    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    // 读入障碍物坐标
    for (int i = 0; i < t; ++i)
    {
        int tx, ty;
        cin >> tx >> ty;
        visited[tx][ty] = true; // 将障碍物直接初始化为已访问状态
    }

    // 特判：如果起点和终点重合，且起点没有障碍（题目保证了）
    if (sx == fx && sy == fy)
    {
        cout << 1 << "\n";
        return 0;
    }

    // 起点本身要标记为已访问，防止后面绕回来重新走到起点
    visited[sx][sy] = true;

    // 开始深度优先搜索
    dfs(sx, sy);

    // 输出最终方案数
    cout << ans << "\n";

    return 0;
}