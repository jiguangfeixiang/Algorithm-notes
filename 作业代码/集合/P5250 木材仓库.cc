// 木材仓库
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
    int m;
    cin >> m;
    set<int> s;
    while (m--)
    {
        int op, length;
        cin >> op >> length;
        if (op == 1)
        {
            if (s.count(length))
            {
                cout << "Already Exist" << endl;
            }
            else
            {
                s.insert(length);
            }
        }
        if (op == 2)
        {
            if (s.empty())
            {
                cout << "Empty" << endl;
                continue;
            }
            auto rightRes = s.lower_bound(length);
            auto finalRes = rightRes;
             if (rightRes !=s.end()&&length==*rightRes)
            {
                finalRes = rightRes;
            }
            else if (rightRes==s.end())
            {
                finalRes = prev(rightRes);
            }
            
            else if (rightRes == s.begin())
            {
                finalRes = s.begin();
            }
            else
            {
                auto leftRes = prev(rightRes);
                int left_diff = length - *leftRes;
                int right_diff = *rightRes - length;
                if (left_diff < right_diff)
                {
                    finalRes = leftRes;
                }
                else
                {
                    finalRes = rightRes;
                }
            }
            cout <<  *finalRes << endl;
            s.erase(finalRes);
        }
    }
}