#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 高精度 A / 低精度 b，r 传入引用以顺便带回余数
vector<int> div(vector<int> &A, long long b, long long &r) {
    vector<int> C;
    r = 0; // r 存储余数
    
    // 从最高位开始算起（因为 A 是倒序的，所以最高位在 A.size() - 1）
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b); // 当前位的商
        r %= b;             // 更新余数
    }
    
    // 因为是从高位到低位 push_back 的，所以此时 C 的最高位在前面
    // 为了和倒序存储统一，我们需要把 C 翻转过来
    reverse(C.begin(), C.end());
    
    // 去除前导零
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string s;
    long long b;
    if (cin >> s >> b) {
        vector<int> A;
        for (int i = s.size() - 1; i >= 0; i--) A.push_back(s[i] - '0');
        long long r = 0; // 余数
        auto C = div(A, b, r);
        
        // 倒序输出商
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
        // 输出余数
     //   cout << "余数: " << r << endl;
    }
    return 0;
}