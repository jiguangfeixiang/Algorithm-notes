// 高精度
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> v1, v2,s;//v1 123  v2 456
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        v1.push_back(s1[i] - '0'); // 字符串转整型  //321 这样v1[0]就是个位数
    }
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        v2.push_back(s2[i] - '0'); // 654 v2[0]6就是个位数
    }
    if (v1.size() < v2.size())
        swap(v1, v2);
    int carry = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int sum = v1[i] + carry + (i < v2.size() ? v2[i] : 0);
        carry = sum / 10;
       // s[i] = sum % 10;//容器没有分配大小直接崩了
        s.push_back(sum % 10);
    }
    if (carry)
        s.push_back(carry);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i];
    }

    return 0;
}
// 高精度
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct highPrecision
// {
//     string digits;
//     highPrecision(string s = "0") : digits(s) {};
//     string operator+(highPrecision& other){
//         string res;
//         res.reserve(max(digits.size(), other.digits.size()) + 1);
//         int i = digits.size() - 1;
//         int j = other.digits.size() - 1;
//         int carry = 0;
//         while (i>=0||j>=0||carry>0)
//         {
//             int sum = carry;
//             if (i>=0)
//             {
//                 sum +=digits[i--] - '0';
//             }
//             if (j>=0)
//             {
//                 sum += other.digits[j--] - '0';
//             }

//             carry = sum / 10;
//             res += sum % 10 + '0';
//         }
//         reverse(res.begin(), res.end());
//         return (res);
//     }

// };
// int main()
// {
//     vector<highPrecision> dp(2);
//     cin >> dp[0].digits >> dp[1].digits;
//     cout << dp[0] + dp[1];
// }
