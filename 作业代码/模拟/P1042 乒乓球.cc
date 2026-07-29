// 乒乓球
#include <iostream>
#include <vector>
using namespace std;
void processRule(vector<char> &v,int target){
    int w=0, l = 0;
    for(auto c : v)
    {
        if (c=='W')
        {
            w++;
        }else if (c=='L')
        {
            l++;  
        }
        if ((w>=target|l>=target)&abs(w-l)>=2)
        {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    cout << w << ":" << l;
}
int main(int argc, char const *argv[])
{
    vector<char> v;
    char c;
    while (cin>>c&&c!='E')
    {
        v.push_back(c);
    }
    processRule(v,11);
    std::cout  << std::endl;
    std::cout  << std::endl;
    processRule(v,21);
    return 0;
}
