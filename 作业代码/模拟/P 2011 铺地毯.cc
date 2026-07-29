#include <iostream>
#include <vector>

using namespace std;

// 定义一个结构体来存储每张地毯的信息
struct Carpet {
    int a, b, g, k;
};

int main() {
    // 优化输入输出，提升效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 数组大小开 n + 1，方便地毯编号从 1 到 n
    vector<Carpet> carpets(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    }
    
    int x, y;
    cin >> x >> y;
    
    // 从最后铺的第 n 张地毯开始倒着往前找
    for (int i = n; i >= 1; i--) {
        // 判断目标点 (x, y) 是否在当前地毯的范围内
        if (x >= carpets[i].a && x <= carpets[i].a + carpets[i].g &&
            y >= carpets[i].b && y <= carpets[i].b + carpets[i].k) {
            
            // 因为是从上往下找，碰到的第一个就是最上面的，直接输出并退出
            cout << i << "\n";
            return 0;
        }
    }
    
    // 如果循环结束了都没有 return，说明没有任何地毯覆盖该点
    cout << -1 << "\n";
    
    return 0;
}