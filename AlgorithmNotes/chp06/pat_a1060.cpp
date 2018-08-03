// 
// pat_a1060.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-21 13:55:09
// 
// PAT A1060
// 
// @Problem
//      Given two numbers,please code to check whether equal with them while it just holds N place decimals,if yes,output YES and given the result of convert,if not,output NO and given the results of convert.
//
// @Thinking
//      first of all,delete precusor number 0
//      two types you should consider:
//          0.a1a2a3
//          b1b2b3.a1a2a3
//      dislodge precusor zero,decimal points and value 0 before non-zero place,then compared
// 
// @Case
//      input: 3 12300 12358.9
//      output: YES 0.123*10^5
//
//
 
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

int n; //valid place
string deal(string s,int& e)
{
    int k = 0; //index of s
    while (s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin()); //delete precusor zero
    }

    if (s[0] == '.')
    {
        s.erase(s.begin()); //delete decimal point
        while (s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin()); //delete the all zero behind of decimal point and before non-zero place
            e--;
        }
    }
    else
    {
        while (k < s.length() && s[k] != '.') //find the decimal point
        {
            k++; 
            e++;
        }

        if (k < s.length()) // met decimal point
        {
            s.erase(s.begin() + k); //delete decimal point
        }
    }
    if (s.length() == 0)
    {
        e = 0; //this number is zero
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n)
    {
        if (k < s.length()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main()
{
    string s1,s2,s3,s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1,e1);
    s4 = deal(s2,e2);
    if (s3 == s4 && e1 == e2)
    {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s3 << "*10^" << e1 << "\t0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
