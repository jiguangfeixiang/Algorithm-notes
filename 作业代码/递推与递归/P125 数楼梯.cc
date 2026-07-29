// 数楼梯
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct highPrecision
{
    string digits;
    highPrecision(string s = "0") : digits(s) {};
    highPrecision operator+(highPrecision& other){
        string res;
        res.reserve(max(digits.size(), other.digits.size()) + 1);
        int i = digits.size() - 1;
        int j = other.digits.size() - 1;
        int carry = 0;
        while (i>=0||j>=0||carry>0)
        {
            int sum = carry;
            if (i>=0)
            {
                sum +=digits[i--] - '0';
            }
            if (j>=0)
            {
                sum += other.digits[j--] - '0';
            }

            carry = sum / 10;
            res += sum % 10 + '0';
        }
        reverse(res.begin(), res.end());
        return highPrecision(res);
    }

};

int main()
{
    int n;
    cin >> n;
    vector<highPrecision> dp(n);
    

    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    if (n == 2)
    {
        cout << "2";
        return 0;
    }
    if (n > 2)
    {
        dp[0]=highPrecision("1");
        dp[1] = highPrecision("2");
        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[n - 1].digits;
        return 0;
    }
}