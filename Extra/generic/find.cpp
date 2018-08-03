// 
// find.cpp
// ianpasm(kno30826@gmail.com)
// 2018-03-11 15:19:36
// 
 
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;

void test1()
{
    int val = 42;
    vector<int> vec(10,42);
    auto result = find(vec.cbegin(),vec.cend(),val);
    cout << "The result " << val << (result == vec.cend()? " is not presennt" : " is present") << endl; 
}

void test2()
{
    string val = "a value";
    list<string> lst(1,"i am not a value!");
    auto result = find(lst.cbegin(),lst.cend(),val);
    cout << "The result " << val << (result == lst.cend()? " is not presennt" : " is present") << endl; 
}

void test3()
{
    int ia[] = {27,100,12,47,109,83};
    int val = 100;
    int* result = std::find(std::begin(ia),std::end(ia),val);
    cout << "The result " << val << (result == std::end(ia)? " is not presennt" : " is present") << endl; 
}

int main()
{
    test3();

    return 0;
}
