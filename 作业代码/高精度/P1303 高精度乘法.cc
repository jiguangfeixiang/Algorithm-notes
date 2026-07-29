#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 高精度 A * 高精度 B
vector<int> mul(vector<int> &A, vector<int> &B) {
    // 两个长度为 n 和 m 的数相乘，结果最多为 n + m 位
    vector<int> C(A.size() + B.size(), 0);
    
    // 1. 对应位相乘并累加
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }
    
    // 2. 统一处理进位
    int t = 0;
    for (size_t i = 0; i < C.size(); i++) {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    
    // 3. 处理前导零
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string s1, s2;
    if (cin >> s1 >> s2) {
        vector<int> A, B;
        for (int i = s1.size() - 1; i >= 0; i--) A.push_back(s1[i] - '0');
        for (int i = s2.size() - 1; i >= 0; i--) B.push_back(s2[i] - '0');
        
        auto C = mul(A, B);
        
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
    }
    return 0;
}
// //
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;
// string mul(string s1, string s2)
// {
//     vector<int> v1, v2;
//     for (int i = s1.size() - 1; i >= 0; i--)
//         v1.push_back(s1[i] - '0');
//     for (int i = s2.size() - 1; i >= 0; i--)
//         v2.push_back(s2[i] - '0');
//     // 两个长度n，m的数相乘，结果最多为n+m位
//     vector<int> ans(v1.size() + v2.size() + 1, 0);
//     for (int i = 0; i < v1.size(); i++)
//     {
//         for (int j = 0; j < v2.size(); j++)
//         {
//             ans[j + i] = ans[i + j] + v1[i] * v2[j];
//             // 处理进位
//             if (ans[i + j] >= 10)
//             {
//                 ans[i + j + 1] += ans[i + j] / 10;
//                 ans[i + j] = ans[i + j] % 10;
//             }
//         }
//     }
//     while (ans.back()==0&&ans.size()>1)
//     {
//         ans.pop_back();
//     }
//     string res;
//     for (int i = ans.size()-1; i >=0; i--)
//     {
//         res += ans[i] + '0';
//     }
//     return res;
// }
// int main()
// {
//     string s1, s2;
//     cin >> s1 >> s2;
//     string res = mul(s1, s2);
//     cout << res;
//     return 0;
// }