//日期之差
//codeup_1928
//思路:先算出较大年份日期的当前天数sum1,再算出较小年份日期当前天数sum2
//则diff = sum1 + (365 - sum2),此为连续年份.
//非连续年份diff = abs(y1 - y2)365 + sum1 + (365 - sum2)
//此段程序有问题,心不在焉,下次修复吧!
//11-18:将两个函数合并为一个,增加了形参,依然有点boom

#include <iostream>
#include <cstdio>
#include <cmath>

//Golobal var
int year1,year2,month1,month2,date1,date2,cur1,cur2,diff;
int day2[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int day1[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int sum1 = 0;
int sum2 = 0;
int leap = 365;//平年天数
int unleap = 366;//闰年天数
int cnt = 0;//闰年个数

void calDate(int year1,int month1,int date1,int year2,int month2,int date2,int cur1,int cur2)
{
    if(year1 > year2)
    {
        int temp = year1;
        year1 = year2;
        year2 = temp;
    }

    for(int i = 0; i < month1; i++)//计算第一个输入的年份日期的当前天数
    {
        if(year1 % 400 == 0 || (year1 % 4 == 0 && year1 % 100 != 0))
        {
            sum1 += day1[i];
            cur1 = sum1 + date1;//当前闰年年份的天数
        }
        else
        {
            sum1 += day2[i];
            cur1 = sum1 + date1;
        }
    }
    
    for(int j = 0; j < month2; j++)//计算第二个输入的年份日期的当前天数
    {
        if(year2 % 400 == 0 || (year2 % 4 == 0 && year2 % 100 != 0))
        {
            sum2 += day1[j]; 
            cur2 = leap - (sum2 + date2);
        }
        else
        {
            sum2 += day2[j]; 
            cur2 = unleap - (sum2 + date2);  
        }    
    }
    
    if (year1 + 1 == year2)//连续年份相差天数
    {
        diff = cur1 + cur2;
        printf("%d\n",diff);
    }
    else//非连续年份相差天数
    {
        for(int i = year1; i <= year2; i++)
        {
            if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            {
                cnt++;
            }
            diff = cur1 + cur2 + cnt*std::abs((year1-year2));
        }
        printf("%d\n",diff);
    }
}

int main()
{
    while(scanf("%d%d%d%d%d%d\n",&year1,&month1,&date1,&year2,&month2,&date2) != EOF)
    {
        calDate(year1,month1,date1,year2,month2,date2,cur1,cur2);
    }

    return 0;
}
