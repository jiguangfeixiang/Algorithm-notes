// 查找
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    for (int j = 0; j < m; j++)
    {
        cin >> q;
        auto it=lower_bound(v.begin(), v.end(), q);
        if(it!=v.end()&&*it==q){
            cout << it - v.begin() + 1 << " ";
        }else{
            cout << "-1 ";
        }
    }
    
    
    return 0;
}

// #include <cstdio>
// const int MAXN = 1000005; // 1e6+5 数组
// int a[MAXN];

// // 查找第一个 >= q 的位置
// int findFirst(int n, int q) {
//     int l = 1, r = n;
//     int ans = -1;
//     while (l <= r) {
//         int mid = l + (r - l) / 2; // 防溢出，等价(l+r)/2
//         if (a[mid] >= q) {
//             ans = mid; // 记录候选位置
//             r = mid - 1; // 往左继续找更早的
//         } else {
//             l = mid + 1;
//         }
//     }
//     // ans是第一个>=q的位置，还要判断是否等于q
//     if (ans != -1 && a[ans] == q) return ans;
//     else return -1;
// }

// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 1; i <= m; i++) {
//         int q;
//         scanf("%d", &q);
//         printf("%d ", findFirst(n, q));
//     }
//     return 0;
// }