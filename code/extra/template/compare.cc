// 
// compare.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-07 10:22:56
// 
 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
int compare1(const T &v1, const T &v2)
{
    if (v1 > v2)
    {
        return 1;
    }
    else 
    {
        return -1;
    }
    return 0;
}

template <unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template <typename T>
int compare3(const T &v1, const T &v2)
{
    if (less<T>() (v1, v2)) return -1;
    if (less<T>() (v2, v1)) return 1;
    return 0;
}


int main()
{
    compare1(3.9, 5.0);
    compare1(1, 4);
    compare2("hi", "joe");
    compare3();
        
    return 0;
}
