//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int a[10][10];
// 定义方向顺序右下左上
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dir = 0; // 0代表右走
int main()
{
    int n;
    cin >> n;
    int x = 1, y = 1;
    for (int i = 1; i <= n * n; i++)
    {
        a[x][y] = i;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 判断下一个位置是否越界  越界进这里  //越界有两个，第一个是有数字，第二个是网格边界
        if (nx < 1 || nx > n || ny < 1 || ny > n && a[nx][ny] != 0)
        {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }
    for (int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= n; j++)
       {
           printf("%3d", a[i][j]);
       }
       cout << endl;
    }
    

    return 0;
}