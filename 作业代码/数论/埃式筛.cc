// // 埃式筛法
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;
// int primes[10000]; // 素数表，存着所有的素数
// bool vis[10000];   // 标记表，标记哪些是合数哪些是素数  1是质数 0是合数
// int count = 0;
// // 求1-n的素数（质数）
// void get_primes(int n)
// {
//     vis[0] = vis[1] = false;     // false 就是0和1不是素数
//     for (int i = 2; i <= n; i++) // 比如我现在是5
//     {
//         if (vis[i] == true)
//         {
//             primes[count++] = i; // i就是素数
//                                  //  埃式核心  用质数去筛合数吧
//             for (int j = 2*i; j <= n; j + i)  //每次用j=i  因为i是素数，所以我用j+i  直到n 我去筛
//             {
//                 vis[j] = false;
//             }
//         }

//         //如果不是质数的话是不是就不用管
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     get_primes(n);

//     return 0;
// }
#include <iostream>
using namespace std;


int primes[10000];
bool vis[10000];

int cnt = 0;


void get_primes(int n)
{

    // 初始化：全部认为是质数
    for(int i=2;i<=n;i++)
    {
        vis[i]=true;
    }


    // 埃氏筛
    for(int i=2;i<=n;i++)
    {

        if(vis[i])
        {
            // i 是质数
            primes[cnt++]=i;


            // 筛掉 i 的倍数
            for(int j=i*i;j<=n;j+=i)//跳过更小的i
            {
                vis[j]=false;
            }
        }

    }

}



int main()
{
    int n;

    cin>>n;


    get_primes(n);


    for(int i=0;i<cnt;i++)
    {
        cout<<primes[i]<<" ";
    }


    return 0;
}
// #include <iostream>
// #include <vector>

// using namespace std;


// vector<int> get_primes(int n)
// {
//     // true 表示目前认为是质数
//     vector<bool> isPrime(n + 1, true);

//     vector<int> primes;


//     // 0 和 1 不是质数
//     isPrime[0] = isPrime[1] = false;


//     for (int i = 2; i <= n; i++)
//     {
//         // 如果 i 还是质数
//         if (isPrime[i])
//         {
//             primes.push_back(i);


//             // 筛掉 i 的倍数
//             if ((long long)i * i <= n)
//             {
//                 for (int j = i * i; j <= n; j += i)
//                 {
//                     isPrime[j] = false;
//                 }
//             }
//         }
//     }


//     return primes;
// }



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