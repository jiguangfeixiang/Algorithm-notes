// 数的计算
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i < n+1; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= i/2; j++)
        {
            f[i] += f[j];
        }
        

        
    }
    cout << f[n] << endl;

    return 0;
}