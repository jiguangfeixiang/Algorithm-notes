//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int main() {
    cin >> n;
    bool is_first = true;
    for (int i = n; i >=0; i--)
    {
        int a;
        cin >> a;
        if (a==0)
        {
            continue;
        }
        else if (a>0)
        {
            if (!is_first)
            {
                cout << "+" ;
            }
        }else{
            cout << "-";
        }
        int abs_a = abs(a);
        if (abs_a!=1||i==0)
        {
            cout << abs_a;
        }
        if(i>1){
            cout << "x^" << i;
        }else if(i==1){
            cout << "x";
        }
        is_first = false;
    }
    
    return 0;
}