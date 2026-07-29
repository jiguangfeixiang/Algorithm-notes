
#include <iostream>
#include <vector>

using namespace std;


vector<int> get_primes(int n)
{
    // true 表示目前认为是质数
    vector<bool> isPrime(n + 1, true);

    vector<int> primes;


    // 0 和 1 不是质数
    isPrime[0] = isPrime[1] = false;


    for (int i = 2; i <= n; i++)
    {
        // 如果 i 还是质数
        if (isPrime[i])
        {
            primes.push_back(i);


            // 筛掉 i 的倍数
            if ((long long)i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }


    return primes;
}

// P3383 线性筛模板

// int main()
// {
//     int n;

//     cin >> n;


//     auto primes = get_primes(n);


//     for (int p : primes)
//     {
//         cout << p << " ";
//     }


//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>

// using namespace std;

// // 使用 std::vector 返回筛出的所有质数
// vector<int> eratosthenes_sieve(int n) {
//     if (n < 2) return {};

//     // 1. 使用 vector<bool> 标记，默认初始化全为 true
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     vector<int> primes;

//     // 2. 埃氏筛核心流程
//     for (int i = 2; i <= n; ++i) {
//         if (is_prime[i]) {
//             primes.push_back(i); // 将质数加入容器
            
//             // i * i 优化：防溢出保护 + 过滤重复筛查
//             if (1LL * i * i <= n) {
//                 for (int j = i * i; j <= n; j += i) {
//                     is_prime[j] = false;
//                 }
//             }
//         }
//     }

//     return primes;
// }

// int main() {
//     // 高级 I/O 优化
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     if (cin >> n >> q) {
//         // 获取所有质数容器
//         const auto primes = eratosthenes_sieve(n);

//         while (q--) {
//             int k;
//             cin >> k;
//             // 直接通过 vector 的下标访问（1-based 转换）
//             cout << primes[k - 1] << "\n";
//         }
//     }

//     return 0;
// }

// 线性筛模板
// #include <iostream>
// #include <vector>

// using namespace std;

// // 线性筛（欧拉筛）模板
// vector<int> euler_sieve(int n) {
//     vector<bool> is_prime(n + 1, true); // 标记数组
//     vector<int> primes;                // 存质数

//     is_prime[0] = is_prime[1] = false;

//     for (int i = 2; i <= n; ++i) {
//         if (is_prime[i]) {
//             primes.push_back(i);
//         }
        
//         // 遍历当前已有的质数
//         for (int p : primes) {
//             if (i * p > n) break;
//             is_prime[i * p] = false; // 用最小质因子筛掉合数
            
//             if (i % p == 0) break;   // 核心：保证 O(N) 复杂度的跳出条件
//         }
//     }

//     return primes;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     if (cin >> n >> q) {
//         vector<int> primes = euler_sieve(n);

//         while (q--) {
//             int k;
//             cin >> k;
//             cout << primes[k - 1] << "\n";
//         }
//     }

//     return 0;
// }

// for (int i = 2; i <= n; ++i) {
//     if (is_prime[i]) {
//         primes.push_back(i);
//     }
    
//     // 用普通下标遍历已保存的质数
//     for (int j = 0; j < primes.size(); ++j) {
//         int p = primes[j];
        
//         if (i * p > n) break;
//         is_prime[i * p] = false; // 用最小质因子筛掉合数
        
//         if (i % p == 0) break;   // 核心：保证 O(N) 复杂度的跳出条件
//     }
// }

// // 埃氏筛
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std; // 把1-n所有的素数给我筛出来放到容器里，返回出去
// vector<int> eratosthenes_sieve(int n)
// {
//     if (n < 2)
//     {
//         return {};
//     }
//     vector<bool> is_primes(n + 1, true); // 判断1-n是不是素数的一个真值表容器
//     is_primes[0] = false;
//     is_primes[1] = false;
//     vector<int> primes; // 素数表
//     for (int i = 2; i <= n; i++)
//     {
//         if (is_primes[i])
//         {
//             // 这个已经判断是质数成功再进来
//             primes.push_back(i);                // 把2，3,5等质数放到容器里
//             for (int j = i * i; j <= n; j += i) // 把2i 3i 4i ... 筛掉
//             {
//                 is_primes[j] = false;
//             }
//         }
//     }
//     return primes;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     auto primes = eratosthenes_sieve(n);
//     for (auto p : primes)
//     {
//         cout << p << " ";
//     }
//     return 0;
// }
// 线性筛
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // 把1-n所有的素数给我筛出来放到容器里，返回出去
vector<int> euler_sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // 这个已经判断是质数成功再进来
            primes.push_back(i);
        }
        // for (auto p : primes)
        // {
        //     if (i * p > n) // 如果i*p大于n，剩下的素数表就不用再遍历了
        //     {
        //         break;
        //     }

        //     is_prime[i * p] = false;
        //     if (i % p == 0)
        //         break;
        // }
        for (int j = 0; j < primes.size();j++)
        {
            int p = primes[j];
            if (i * p > n) // 如果i*p大于n，剩下的素数表就不用再遍历了
            {
                break;
            }

            is_prime[i * p] = false;
            if (i % p == 0)
                break;
        }
    }
    return primes;
}
int main()
{
    int n;
    cin >> n;
    auto primes = euler_sieve(n);
    for (auto p : primes)
    {
        cout << p << " ";
    }
    return 0;
}