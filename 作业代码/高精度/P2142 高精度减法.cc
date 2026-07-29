#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 💡 模块 1：绝对值大比武 A >= B (用于小减大时调换顺序)
// 如果 a 比 b 位数多，直接返回 true。
// 如果位数相等，字符串自带的默认 >= 运算符（字典序比较）在物理上等价于数值比较。
bool comp(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}

// 💡 模块 2：高精度减法核心算法（严格保证调用时 s1 >= s2）
vector<int> sub(const string& s1, const string& s2) {
    vector<int> res;
    int borrow = 0; // 借位哨兵

    // 💡 物理指针融合：完美地将初始指针、边界判定、指针递减全部锁进 for 循环中
    // 指针 i 和 j 直接从字符串末尾（即个位）逆向往下扫描
    for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0; i--, j--) {
        // 先拿出 A 的当前位数字，并无情地扣掉右边借走的那一口气
        int t = (s1[i] - '0') - borrow;

        // 如果 B 还没掏空，就把它对应的数字也减掉
        if (j >= 0) t -= (s2[j] - '0');

        // 💡 核心借位魔法（数学公式一行流）：
        // 若 t >= 0，(t + 10) % 10 依然是 t，并将 borrow 哨兵置 0（够减）
        // 若 t < 0，(t + 10) % 10 会自动帮它借一个 10 当考山，并将 borrow 哨兵置 1（不够减）
        res.push_back((t + 10) % 10);
        
        // 更新借位
        borrow = (t < 0) ? 1 : 0;
    }

    // 💡 物理陷阱：消除前导零！比如 1003 - 1000 = 0003，必须把高位的 0 弹出
    // 注意留底：如果结果正好是 0（比如 5 - 5），至少要留一个单独的 0，不能全弹光了。
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    return res;
}

int main() {
    // 考场黄金优化：关同步、系 nullptr
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (cin >> s1 >> s2) {
        // 💡 符号大判断：小数减大数？先把负号打印出来，再反过来用大减小。
        if (!comp(s1, s2)) {
            cout << "-";
            swap(s1, s2);
        }

        // 此时，s1 必然是绝对值大的那一个。
        vector<int> res = sub(s1, s2);

        // 💡 res 是倒序压入的（res.back() 是最高位），最后通过循环倒序打印出来。
        for (int i = res.size() - 1; i >= 0; i--) {
            cout << res[i];
        }
        cout << "\n";
    }

    return 0;
}
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// // 💡 基础模块：比较绝对值大小 A >= B
// bool comp(const string& a, const string& b) {
//     if (a.size() != b.size()) return a.size() > b.size();
//     return a >= b;
// }

// // ==================== 1. 统一框架：高精度加法 ====================
// string add(string s1, string s2) {
//     vector<int> v1, v2, res;
//     // 统一倒序入栈（v[0] 为个位）
//     for (int i = s1.size() - 1; i >= 0; i--) v1.push_back(s1[i] - '0');
//     for (int i = s2.size() - 1; i >= 0; i--) v2.push_back(s2[i] - '0');

//     int carry = 0; // 进位
//     size_t len = max(v1.size(), v2.size());

//     // 统一的双指针 / 长度同步扫描
//     for (size_t i = 0; i < len || carry > 0; i++) {
//         int sum = carry;
//         if (i < v1.size()) sum += v1[i];
//         if (i < v2.size()) sum += v2[i];

//         res.push_back(sum % 10);
//         carry = sum / 10;
//     }

//     // 转回 string 输出
//     string ans = "";
//     for (int i = res.size() - 1; i >= 0; i--) ans += (res[i] + '0');
//     return ans;
// }

// // ==================== 2. 统一框架：高精度减法 ====================
// // 核心减法（严格限定 s1 >= s2，即大减小）
// string sub_core(string s1, string s2) {
//     vector<int> v1, v2, res;
//     // 统一倒序入栈（v[0] 为个位）
//     for (int i = s1.size() - 1; i >= 0; i--) v1.push_back(s1[i] - '0');
//     for (int i = s2.size() - 1; i >= 0; i--) v2.push_back(s2[i] - '0');

//     int borrow = 0; // 借位

//     // 统一的双指针 / 长度同步扫描
//     for (size_t i = 0; i < v1.size(); i++) {
//         int t = v1[i] - borrow;
//         if (i < v2.size()) t -= v2[i];

//         res.push_back((t + 10) % 10);
//         borrow = (t < 0) ? 1 : 0;
//     }

//     // 减法特有的物理特性：抹除前导零
//     while (res.size() > 1 && res.back() == 0) {
//         res.pop_back();
//     }

//     // 转回 string 输出
//     string ans = "";
//     for (int i = res.size() - 1; i >= 0; i--) ans += (res[i] + '0');
//     return ans;
// }

// // 对外调度接口（处理负号）
// string sub(string s1, string s2) {
//     if (!comp(s1, s2)) {
//         return "-" + sub_core(s2, s1);
//     }
//     return sub_core(s1, s2);
// }
// ==================== 3. 统一框架：高精度乘法 ====================
// string mul(string s1, string s2) {
//     vector<int> v1, v2;
//     // 1. 统一倒序入栈（v[0] 为个位）
//     for (int i = s1.size() - 1; i >= 0; i--) v1.push_back(s1[i] - '0');
//     for (int i = s2.size() - 1; i >= 0; i--) v2.push_back(s2[i] - '0');

//     // 两个长度分别为 n 和 m 的数相乘，结果最多为 n + m 位
//     vector<int> res(v1.size() + v2.size(), 0);

//     // 2. 对应位相乘并累加到 C[i + j]
//     for (size_t i = 0; i < v1.size(); i++) {
//         for (size_t j = 0; j < v2.size(); j++) {
//             res[i + j] += v1[i] * v2[j];
//         }
//     }

//     // 3. 统一处理进位
//     int carry = 0;
//     for (size_t i = 0; i < res.size(); i++) {
//         carry += res[i];
//         res[i] = carry % 10;
//         carry /= 10;
//     }

//     // 4. 抹除前导零（防止 0 * 0 得到 "00"）
//     while (res.size() > 1 && res.back() == 0) {
//         res.pop_back();
//     }

//     // 5. 转回 string 输出
//     string ans = "";
//     for (int i = res.size() - 1; i >= 0; i--) {
//         ans += (res[i] + '0');
//     }
//     return ans;
// }
// // ==================== 测试主函数 ====================
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string a = "1002", b = "999";
    
//     cout << "加法结果: " << add(a, b) << "\n"; // 2001
//     cout << "减法结果: " << sub(a, b) << "\n"; // 3
//     cout << "小减大结果: " << sub(b, a) << "\n"; // -3

//     return 0;
// }