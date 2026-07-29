// 选举学生会问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(auto v1 : v)
    {
        cout << v1 << " ";
    }
    return 0;
}