#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 高精度加法函数：输入两个数字字符串，返回相加后的字符串
string add(string s1, string s2) {
    vector<int> v1, v2, s;

    // 1. 倒序存入 vector，让 v[0] 变成个位
    for (int i = s1.size() - 1; i >= 0; i--) {
        v1.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0; i--) {
        v2.push_back(s2[i] - '0');
    }

    // 2. 保证 v1 是较长的那一个
    if (v1.size() < v2.size()) {
        swap(v1, v2);
    }

    // 3. 逐位相加
    int carry = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        int sum = v1[i] + carry + (i < v2.size() ? v2[i] : 0);
        carry = sum / 10;
        s.push_back(sum % 10);
    }

    // 4. 处理最后的最高位进位
    if (carry) {
        s.push_back(carry);
    }

    // 5. 将 vector 逆序拼接还原为字符串返回
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        res += to_string(s[i]); // 或者 res += (s[i] + '0');
    }

    return res;
}

int main() {
    // 优化 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (cin >> s1 >> s2) {
        // 调用封装好的函数
        cout << add(s1, s2) << "\n";
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