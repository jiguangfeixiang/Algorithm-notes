// 淘汰赛
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int teams = pow(2, n);
    int halfTeams = teams / 2;
    int leftMax = -1, leftId = -1;
    int rightMax = -1, rightId = -1;
    for (int i = 1; i <= halfTeams; i++)
    {
        int power;
        cin >> power;
        if(power>leftMax){
            leftMax = power;
            leftId = i;
        }
    }
    for (int i = halfTeams+1; i <= teams; i++)
    {
        int power;
        cin >> power;
        if(power>rightMax){
            rightMax = power;
            rightId = i;
        }
    }
    if (leftMax>rightMax)
    {
        cout << rightId;
    }else{
        cout << leftId;
    }
    
    

    return 0;
}