 // 
 // pat_b1009.cpp
 // ianpasm(kno30826@gmail.com)
 // 2017-11-21 15:17:07
 // 
 //pat-b1009 说反话

#include <cstdio>
#include <cstring>
#include <cstdlib>
 
int main()
{
    char str[90];
    gets(str);
    int len = strlen(str);
    int r = 0;//行
    int c = 0;//列
    char ans[90][90];
    for (int i = 0; i < len; i++)
    {
       if (str[i] != ' ')
       {
           ans[r][c++] = str[i];//若不是空格，则将输入的字符串存入ans[r][c],并移至下个位置
       }
       else//如果是空格，说明一个单词结束，r增加１,c置０
       {
           ans[r][c] = '\0';
           r++;
           c = 0;
       }
    }
    for (int i = r; i >= 0; i--)//逆序输出单词
    {
        printf("%s",ans[i]);
        if(i > 0)
            printf(" ");
    }

    return 0;
}
