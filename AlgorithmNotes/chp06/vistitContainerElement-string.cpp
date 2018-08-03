// 
// vistitContainerElement-string.cpp
// ianpasm(kno30826@gmail.com)
// 2018-02-26 09:50:09
// 

#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
using std::cout;
using std::endl;
using std::string;
using std::iterator;

int main()
{
    string str = "abcd";

    //01
    //for (int i = 0; i < str,length(); i++)
    //{
    //    printf("%c",str[i]);
    //}

    //02
    //cin >> str;
    //cout << str;

    //03
    //printf("%s\n",str.c_str());

    //04
    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        printf("%c",*it);
    }

    return 0;
}

