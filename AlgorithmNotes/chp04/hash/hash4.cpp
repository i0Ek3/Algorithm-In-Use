// 
// hash4.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-08 19:42:14
//
// 字符串hash初步
// 如何将一个二维正点P的坐标映射为一个整数，使得整点P可以由该整数唯一的代表
// 字符串hash即将一个字符串S映射为一个整数，使得该整数可以尽可能唯一地代表该字符串S
// 
// 思路：将26进制转换为10进制则可以唯一的表示真点坐标P
//
//
// 1.A-Z
// int hashFunc(char S[],int len)
// {
//      int id = 0;
//      for (int i = 0; i < len; i++)
//      {
//          id = id * 26 + (S[i] - 'A');
//      }
//      return id;
// }
// 
// 2.A-Z a-z
// int hashFunc(char S[],int len)
// {
//      int id = 0;
//      for (int i = 0; i < len; i++)
//      {
//          if (S[i] > 'A' && S[i] < 'Z')
//          {
//              id = id * 52 + (S[i] - 'A');
//          }else if (S[i] > 'a' && S[i] < 'z')
//          {
//              id = id * 52 + (S[i] - 'a') + 26;
//          }
//      }
//      return id;
// }
//
// 3.alphiabet with digits
// Example:BCD4
// int hashFunc(char S[],int len)
// {
//      int id = 0;
//      for (int i = 0; i < len - 1; i++)
//      {
//          id = id * 26 + (S[i] - 'A');
//      }
//      id = id * 10 + (S[len - 1] - '0');
//      return id;
// }
//
//Question:
//  Given n strings made of 3 upper alphabets,m query strings.
//  Please answer how times of m appeared in n?
//  n:ABC
//  m:ABC
//    ABCD
//    ABC4
//    abc
//    abc4
//
//

#include <cstdio>
const int maxn = 100;
char S[maxn][5],temp[5];
int hashTable[26 * 26 * 26 + 10];

int hashFunc(char S[],int len)
{
    int id = 0;
    for (int i = 0; i < len; i++)
    {
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}

int main()
{
    int n,m;
    printf("Plz enter digits n & m:\n");
    scanf("%d %d",&n,&m);
    printf("Plz enter %d strings:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",S[i]);
        int id = hashFunc(S[i],3); //This step change S[i] to integret.
        hashTable[id]++;
    }
    printf("Plz enter %d strings:\n",m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s",temp);
        int id = hashFunc(temp,3);
        printf("%d\n",hashTable[id]);
    }
    return 0;
}

