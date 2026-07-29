// 部分背包问题
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
    int m;
    int v;
    double portion;
};
double compare(Node &a,Node &b){
    return a.portion > b.portion;
}
int main() {
    int N, T;
    cin >> N >> T;
    vector<Node> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].m >> v[i].v;
        v[i].portion = (double)v[i].v / v[i].m;
    }
    sort(v.begin(), v.end(), compare);
    double res=0;
    for (int i = 0; i < N; i++)
    {
        if(T>=v[i].m){
            res += v[i].v;
            T -= v[i].m;
        }else{
            res += T * v[i].portion;
            break;
        }
    }
    printf("%.2f", res);

    return 0;
}