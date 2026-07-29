// A-B数对
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
// // map方法
// int main() {
//     long N, C;
//     cin >> N >> C;
//     vector<long> a(N);
//     map<long, long> cnt;

//     for (long i = 0; i < N; i++)
//     {
//         cin >> a[i];
//         cnt[a[i]]++;//这个值对应的次数
//     }
//     long res=0;
//     for (long i = 0; i < N; i++)
//     {
//         if (cnt[a[i]+C])
//         {
//             res+=cnt[a[i]+C];
//         }
        
//     }
//     cout << res << endl;

//     return 0;
// }
// 二分法
int main(int argc, char const *argv[])
{
    int N;
    long C;
    cin >> N>>C;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long target;
    long ans = 0;
    for (int i = 0; i < N; i++)
    {
        target = v[i] + C;
        auto r = upper_bound(v.begin(), v.end(), target);
        auto l = lower_bound(v.begin(), v.end(), target);
        ans += r - l;
    }
    cout << ans;

    return 0;
}
