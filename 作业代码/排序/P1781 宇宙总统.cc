//宇宙总统题
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    int x, y, z;
};
int compare(Node& a,Node&b){
    return a.z < b.z;
}
int main() {
    int n = 0;
    cin >> n;
    vector<Node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }
    sort(v.begin(), v.end(), compare);
    double res=0;
    for (int i = 1; i < n; i++)
    {
        res += sqrt((pow((v[i].x - v[i - 1].x),2) + pow((v[i].y - v[i - 1].y), 2) +pow( (v[i].z - v[i - 1].z) ,2)));
    }
    printf(".3f", res);
}