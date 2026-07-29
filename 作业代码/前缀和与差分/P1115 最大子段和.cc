// 最大字段和
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum=0;
    int minSum = 0;
    int maxSum = -2e9;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        maxSum = max(sum - minSum, maxSum);

        minSum = min(sum, minSum);

//         这里有一个严重的逻辑漏洞：你在算 sum - minSum 之前，先把当前的 sum 放进 minSum 里去比较了。
// 如果当前的 sum 刚好创造了历史新低，那么 minSum 就会变成当前的 sum。接下来算 sum - minSum 时，就变成了 sum - sum = 0。
// 这会导致：如果最大子段和的右端点正好是一个极小的负数（或者全部都是负数时），你永远在拿当前位置减去当前位置，算出来的区间和变成了 0，从而把正确答案给漏掉了。

// 修改方案：应该先计算 maxSum，然后再更新 minSum。确保减去的 minSum 是当前位置左边的历史最低谷。
    }
    cout << maxSum;

    return 0;
}