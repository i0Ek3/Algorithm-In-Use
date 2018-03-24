// 
// pair.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-24 10:44:26
// 
 
#include <iostream>
#include <utility>
#include <string>
#include <map>
using std::map;
using std::string;
using std::pair;
using std::cout;
using std::endl;

void compare()
{
    pair<int,int> p1(1,2);
    pair<int,int> p2(1,3);
    pair<int,int> p3(2,2);
    if (p1 < p3) cout << "p1 < p3\n";
    if (p1 <= p3) cout << "p1 <= p3\n";
    if (p1 < p2) cout << "p1 < p2\n";
}

void visit()
{
    pair<string,int> p;
    p.first = "first";
    p.second = 4;
    cout << p.first << " " << p.second << endl;

    p = std::make_pair("second",5);
    cout << p.first << " " << p.second << endl;

    p = pair<string,int> ("third",6);
    cout << p.first << " " << p.second << endl;
}

void use()
{
    map<string,int> mp;
    mp.insert(std::make_pair("easy",5));
    mp.insert(pair<string,int>("hard",6));
    for (map<string,int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    compare();
    visit();
    use();
    
    return 0;
}
