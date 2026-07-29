//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
vector<int> G[100005];
vector<bool> vis_dfs(100005, false);
int dist[100005];
int parent[100005];
void dfs(int start)
{
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
vector<bool> vis_bfs(100005, false);
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis_bfs[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < G[current].size(); i++)
        {
            int next_node = G[current][i];
            if (!vis_bfs[next_node])
            {
                dist[next_node] = dist[current] + 1;
                parent[next_node] = current;
                vis_bfs[next_node] = true;
                q.push(next_node);
            }
        }
    }
}
void printPath(int n){
    vector<int> path;
    for (int current = n; current !=0; current=parent[n])
    {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());
    for(auto path1 : path)
    {
        cout << path1 << " ";
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
    for (int i = 1; i <= n; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    printPath(8);
    return 0;
}