// 八皇后
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<bool> colHaveFlag;
vector<bool> mainDiag;
vector<bool> auxiDiag;
vector<int> ans;
int n;
int totalSolution = 0;
int dfs(int row)
{
    if (row > n)
    {
        totalSolution++;
        if (totalSolution <= 3)
        {
            for (int i = 1; i < n + 1; i++)
            {
                cout << ans[i] << (i == n ? "" : " ");
            }
            cout << endl;
        }
        return 0;
    }
    for (int j = 1; j < n+1; j++)
    {
        if (!colHaveFlag[j] && !mainDiag[row - j + n] && !auxiDiag[row + j])
        {
            colHaveFlag[j] = true;
            mainDiag[row - j + n] = true;
            auxiDiag[row + j] = true;
            ans[row] = j;
            dfs(row + 1);

            colHaveFlag[j] = false;
            mainDiag[row - j + n] = false;
            auxiDiag[row + j] = false;
        }
    }
}
int main()
{
    cin >> n;
    colHaveFlag.resize(n + 1, false);
    mainDiag.resize(2 * n + 1, false);
    auxiDiag.resize(2 * n + 1, false);
    ans.resize(n + 1);

    dfs(1);
    cout << totalSolution;

    return 0;
}