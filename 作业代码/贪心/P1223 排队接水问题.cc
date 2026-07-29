// 排队接水问题
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Person
{
    int id;
    int time;
};
double compare(Person &a,Person &b){
    if (a.time!=b.time)
    {
        return a.time < b.time;
    }
    
    return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    vector<Person> T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i].time;
        T[i].id = i+1;
    }
    sort(T.begin(), T.end(), compare);
    double avergeTime = 0;

    for (int i = 0; i < n; i++)
    {
        avergeTime += T[i].time * (n - i - 1);
        cout << T[i].id << " ";
    }
    cout << "\n";
    avergeTime = (double)(avergeTime / (n));
    printf("%.2f", avergeTime);

    return 0;
}