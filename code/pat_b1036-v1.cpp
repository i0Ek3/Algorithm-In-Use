// 图形输出之ianpasm版本

#include <iostream>
#include <cstdio>

void blank(int a) //中间部分的空格输出
{
    for(int i = 0; i < a-2; i++)
    {
        printf(" ");
    }
}

void printM(int a,char ch) //中间部分输出
{
    for(int i = 0; i < a % 2 - 2; i++) //erroe in here
    {
        printf("%c",ch);
        blank(a);
        printf("%c\n",ch);
    }
}

void print() //整体轮廓输出
{
    int a;
    char ch;
    while(scanf("%d %c",&a,&ch) != EOF) //循环输入
    {
        for(int i = 0; i < a; i++) //第一行
        {
            printf("%c",ch);
        }
        printf("\n");
        printM(a,ch);
        for(int i = 0; i < a; i++) //最后一行
        {            
            printf("%c",ch);
        }
        printf("\n");
    }   
}

int main()
{
    print();
    return 0;
}
