#include <iostream>
#include <vector>

using namespace std;

// 全局变量，用来存储逆序对总数，必须是 long long
long long ans = 0;

// temp 数组作为归并排序的临时辅助空间
vector<int> temp;

// 归并排序函数，区间为 [l, r]
void merge_sort(vector<int> &a, int l, int r) {
    if (l >= r) return; // 边界条件：区间只有一个数或为空，停止划分

    int mid = l + (r - l) / 2;

    // 分治：递归让左半边有序，右半边有序
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    // 核心：合并两个有序序列
    int i = l;       // 左半边的起点
    int j = mid + 1; // 右半边的起点
    int k = l;       // 辅助数组的写入起点

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            // 如果左边小，正常放入，不触发逆序
            temp[k++] = a[i++];
        } else {
            // 如果右边小，说明当前左边指针 i 及其后面的所有数，都比 a[j] 大！
            temp[k++] = a[j++];
            ans += (mid - i + 1); // 极其关键：批量累加逆序对数量
        }
    }

    // 把左边或右边没漏掉的尾巴补齐
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    // 将排好序的临时数组 temp 复制回原数组 a 中
    for (int idx = l; idx <= r; idx++) {
        a[idx] = temp[idx];
    }
}

int main() {
    // 极速输入输出优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        temp.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 开展归并排序
        merge_sort(a, 0, n - 1);

        cout << ans << "\n";
    }

    return 0;
}