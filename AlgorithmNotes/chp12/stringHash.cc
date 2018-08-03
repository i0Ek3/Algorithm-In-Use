// 
// stringHash.cc
// @ianpasm(kno30826@gmail.com)
// 2018-07-01 14:49:28
//
// @Problem
//  
//  Given N strings which is only made by lowercase. Reslut the numbers of different string.
//
//
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::string;
using std::vector;

const int MOD = 1e9 + 7;
const int P = 1e7 + 19;

vector<int> vi;

long long stringToInt(string str) 
{
    long long H = 0;
    for (int i = 0; i < str.length(); i++) {
        H = ( H * P + str[i] - 'a') % MOD;  
    }
    return H;
}

int main()
{
    string str;
    while (getline(std::cin, str), str != "#") {
        long long id = stringToInt(str);
        vi.push_back(id);
    }
    sort(vi.begin(), vi.end());
    int count = 0;
    for (int i = 0; i < vi.size(); i++) {
        if (i == 0 || vi[i] != vi[i-1]) {
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}


