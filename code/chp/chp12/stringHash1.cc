// 
// stringHash1.cc
// @ianpasm(kno30826@gmail.com)
// 2018-07-02 20:45:49
// 
// @Problem
//      
//      Input two strings which length are less than 1000 chars, result the length of the longest common substring.
//
//
//
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
using std::string;
using std::map;
using std::vector;
using std::algorithm;
using std::cin;
using std::cout;
using std::endl;

typedef long long LL;
const LL MOD = 1e9 + 7;
const LL P = 1e7 + 19;
const LL MAXN = 1010;
LL powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0}; //powP[] storage P^i%MOD, H[] storage str's hash
vector<pair<int, int>> pr1, pr2; //storage the key-value <substr hash, substr length> for str

void init(int len)
{
    powP[0] = 1;
    for (int i = 1; i <= len; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

void calHash(LL H[], string &str)
{
    H[0] = str[0];
    for (int i = 1; i < str.length(); i++) {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

void calSingleSubHash(LL H[], int i, int j)
{
    if (i == 0) {
        return H[j];
    }
    return ((H[j] - H[i - 1] * powP[j - 1 + i]) % MOD + MOD) % MOD;
}

void calSubHash(LL H[], int len, vector<pair<int, int>>&pr)
{
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            int hashValue = calSingleSubHash(H, i, j);
            pr.push_back(make_pair(hashValue, j - i + 1));
        }
    }
}

int getMax()
{
    int ans = 0;
    for (int i = 0; i < pr1.size(); i++) {
        for (int j = 0; j < pr2.size(); j++) {
            if (pr1[i].first == pr2[j].first) {
                ans = std::max(ans, pr1[i], pr2[j]);
            }
        }
    }
    return ans;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    init(std::max(str1.length(), str2.length())); //initialize powP[]
    calHash(H1, str1);
    calHash(H2, str2);
    calSubHash(H1, str1.length(), pr1);
    calSubHash(H2, str2.length(), pr2);
    printf("ans = %d\n",getMax());

    return 0;
}


