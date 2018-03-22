// 
// map.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-22 09:17:43
// 

#include <iostream>
#include <map>
#include <string>
#include <iterator>
using std::iterator;
using std::string;
using std::map;
using std::cout;
using std::endl;

int main()
{
    map<string,int> mp;
    mp["hello"] = 1;
    mp["world"] = 2;
    mp["mmp"] = 0;
    map<string,int>::iterator it = mp.find("mmp");
    mp.erase(it);
    for (map<string,int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << it -> first
             << it -> second
             << endl;
    }
    return 0;
}
