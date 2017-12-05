// 
// stringSort.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-05 10:44:18
// 
 
#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;

#if 0
bool cmp(string s1,string s2)
{
    return s1 > s2;
}
#endif

int main()
{
    string str[3] = {"aaa","bbb","cccc"};
    sort(str,str + 3);
    for (int i = 0; i < 3; i++)
    {
        cout << str[i] << endl;
    }

    return 0;
}
