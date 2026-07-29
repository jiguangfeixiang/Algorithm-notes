// 临时抱佛脚问题 01背包问题
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int subjectId = 0;
vector<int> subjectProblemCounts(5);
int examTotalTime = 0;
int calSubjectMinTime(int subjectId){
    int currentProblemCounts = subjectProblemCounts[subjectId];
    vector<int> problemTimeV(currentProblemCounts);
    int subjectTotalTime = 0;
    for (int i = 0; i < currentProblemCounts; i++)
    {
        cin >> problemTimeV[i];
        subjectTotalTime += problemTimeV[i];
    }
    int W = subjectTotalTime / 2;//背包问题求出来左脑最大时间
    vector<int> maxTimeDp(W + 1);
    for (int i = 0; i < currentProblemCounts; i++)
    {
        for (int j = W; j >=problemTimeV[i]; j--)
        {
            maxTimeDp[j] = max(maxTimeDp[j], maxTimeDp[j - problemTimeV[i]] + problemTimeV[i]);
        }
        
    }
    int leftBrainTime = maxTimeDp[W];
    int rigthBrainTime = subjectTotalTime - leftBrainTime;
    return rigthBrainTime;
}
int main() {
    for (int subjectId = 1; subjectId <=4; subjectId++)
    {
        cin >> subjectProblemCounts[subjectId];
    }
    for (int i = 1; i <=4; i++)
    {
        examTotalTime += calSubjectMinTime(i);
    }
    cout << examTotalTime;

    return 0;
}