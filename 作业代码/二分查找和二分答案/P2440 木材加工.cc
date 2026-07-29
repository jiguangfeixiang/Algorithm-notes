// 木材加工  二分答案
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, k;
vector<int> v;
double check(int len){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        count += v[i] / len;
    }
    return count >= k;
}


int main() {
    cin >> n >> k;
    v.resize(n);
    int maxValue=0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxValue = max(maxValue, v[i]);
    }
    int left = 1, right = maxValue;
    int ans;
    while (left<=right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid))
        {
        ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << left <<" " <<right <<" "<< ans;

    return 0;
}