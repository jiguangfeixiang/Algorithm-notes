// 医院设置
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n;

struct Node
{
    int w;
    vector<int> neighbor;
};
vector<Node> tree;

int getTotalVal(int start)
{
    queue< pair<int, int> > q;
    vector<bool> visited(n + 1, false);
    q.push({start, 0});
    visited[start] = true;
    int  totalDist=0;

    while (!q.empty())
    {
        auto [current, dist] = q.front();
        q.pop();
        totalDist+= tree[current].w * dist;
        for(auto neighbor : tree[current].neighbor)
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
            
        }
    }
    return totalDist;
}
int main()
{
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >>w>> u >> v ;
        tree[i].w = w;
        if (u != 0)
        {
            tree[i].neighbor.push_back(u);
            tree[u].neighbor.push_back(i);
        }
        if (v != 0)
        {
            tree[i].neighbor.push_back(v);
            tree[v].neighbor.push_back(i);
        }
    }
    int  minVal = 1e18;
    for (int i = 1; i <= n; i++)
    {
        int  currentDistance = getTotalVal(i);
        minVal = min(minVal, currentDistance);
    }
    cout<<minVal;

    // 建立二叉树 邻接表
    return 0;
}