//马的遍历
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
vector<int> dx{-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dy{-1, 1, -2, 2, -2, 2, -1, 1};
struct Node
{
    int x, y;
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector < vector<int>> pos(n + 1, vector<int>(m + 1, -1));
    queue<Node> q;
    q.push({x, y});
    pos[x][y] = 0;
    while (!q.empty())
    {
        Node currentPos = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nextX = currentPos.x + dx[i];
            int nextY = currentPos.y + dy[i];
            if (nextX>=1&&nextX<=n&&nextY>=1&&nextY<=m&&pos[nextX][nextY]==-1)
            {
                pos[nextX][nextY] = pos[currentPos.x][currentPos.y] + 1;
                q.push({nextX, nextY});
            }
            
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << pos[i][j] << (j == m ? "" : " ");
        }
        cout << endl;
    }
    
    

    return 0;
}