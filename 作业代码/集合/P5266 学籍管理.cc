// 学籍管理
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, int> student;
    string name;
    int op, score;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> name >> score;
            student[name] = score;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            cin >> name;
            auto it = student.find(name);
            if (it == student.end())
            {
                cout << "Not found" << endl;
            }
            else
            {
                cout << it->second << endl;
            }
        }
        else if (op == 3)
        {
            cin >> name;
            auto it = student.find(name);
            if (it == student.end())
            {
                cout << "Not found" << endl;
            }
            else
            {
                student.erase(name);
                cout << "Deleted successfully\n";
            }
        }
        else if (op == 4)
        {
            cout << student.size() << endl;
        }
    }

    return 0;
}