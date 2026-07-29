#include<iostream>
#include <vector>
using namespace std;


vector<vector<int>> tree;


// DFS函数
void dfs(int u, int father)
{
    // 访问当前节点
    cout << u << " ";


    // 遍历相邻节点
    for(int v : tree[u])
    {
        // 防止回到父节点
        if(v == father)
            continue;


        dfs(v, u);
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;


    // n+1个节点，下标从1开始
    tree.resize(n + 1);



    // 输入n-1条边
    for(int i = 1; i < n; i++)
    {
        int u, v;

        cin >> u >> v;


        // 无根树，双向存储
        tree[u].push_back(v);

        tree[v].push_back(u);
    }



    // 从1号节点开始遍历
    dfs(1, 0);


    return 0;
}