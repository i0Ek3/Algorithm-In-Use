// 
// pat_b1040.cpp
// ianpasm(kno30826@gmail.com)
// 2018-02-01 10:34:12
// 
//
// PAT B1040/A1093
// How many PAT?
// The string APPAPT includes two words 'PAT',
//            123456
// made form   2 4 6
// and          34 6
// Now given the string,how many word 'PAT' I can get?
//
// input:APPAPT
// output:2
 
#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = {0}; //每一位左边含P的个数

int main()
{
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) //从左到右遍历字符串
    {
        if (i > 0) //若不是0位则继承上一位的结果
        {
            leftNumP[i] = leftNumP[i-1];
        }
        if (str[i] == 'P') //当前位是P位，则另leftNumP加一
        {
            leftNumP[i]++;
        }
    }
    int ans = 0,rightNumT = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == 'T')
        {
            rightNumT++;
        }
        else if (str[i] == 'A')
        {
            ans = (ans + leftNumP[i] * rightNumT) % MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
