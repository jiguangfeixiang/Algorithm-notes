#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 上下左右四个方向
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    int start_x = -1, start_y = -1;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'k') {
                start_x = i;
                start_y = j;
            }
        }
    }

    // dist[i][j] 记录起始点到 (i, j) 的步数，初始化为 -1 表示未访问
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Point> q;

    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;

    int reach_exit_cnt = 0;
    int min_dist = 1e9;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 越界检查（包含外层岩浆防护）
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 遇到墙壁或已访问过的点，跳过
            if (grid[nx][ny] == '*' || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cur.x][cur.y] + 1;

            // 如果到达出口
            if (grid[nx][ny] == 'e') {
                reach_exit_cnt++;
                min_dist = min(min_dist, dist[nx][ny]);
                // 注意：到达出口后离开迷宫，不入队继续延伸
            } else {
                // 普通道路 '.' 或起点继续拓展
                q.push({nx, ny});
            }
        }
    }

    if (reach_exit_cnt == 0) {
        cout << -1 << "\n";
    } else {
        cout << reach_exit_cnt << " " << min_dist << "\n";
    }

    return 0;
}