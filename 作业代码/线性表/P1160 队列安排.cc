// 队列安排
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    list<int> queueList;
    vector<list<int>::iterator> pos(N + 1);
    queueList.push_back(1);
    pos[1] = queueList.begin(); // pos第一个位置就是同学1，只是存的是1的迭代器但是我们把这个迭代器当做1
    for (int currentId = 2; currentId <= N; currentId++)
    {
        int k, p;
        cin >> k >> p; // k是第k个同学，p为0要插入k同学的左边
        if (p == 0)
        {
            pos[currentId] = queueList.insert(pos[k], currentId);
        }
        else
        {
            auto nextPos = pos[k];
            nextPos++;
            pos[currentId] = queueList.insert(nextPos, currentId);
        }
    }

    vector<int> isStillQueV(N+1,false);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int removeId;
        cin >> removeId;
        if (!isStillQueV[removeId])
        {
            queueList.erase(pos[removeId]);
            isStillQueV[removeId] = true;
        } 
    }
    for(auto classmate : queueList)
    {
        cout << classmate << " ";
    }

    return 0;
}