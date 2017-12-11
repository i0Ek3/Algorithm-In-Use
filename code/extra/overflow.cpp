// 
// overflow.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-11 08:58:17
// 
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    short short_v = 32767;
    short_v += 2;
    cout << short_v << endl;
    cout << "==========================" << endl;
    int x1 = -21 % -8;
    int x2 = 21 % -8;
    cout << "x1=" << x1 << "x2=" << x2;
    return 0;
}
