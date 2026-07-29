//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gragh_matrix(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> graph_table(n + 1);
    
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gragh_matrix[u][v] = 1;
        gragh_matrix[v][u] = 1;

        graph_table[u].push_back(v);
        graph_table[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << gragh_matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph_table[i].begin(), graph_table[i].end());
        cout << graph_table[i].size() << " ";
        for (auto v : graph_table[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    

    return 0;
}