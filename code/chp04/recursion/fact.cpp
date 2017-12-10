// 
// fact.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-09 08:51:19
// 
 
#include <cstdio>

int fact(int n)
{
    if (0 == n) return 1; //recursion borden
    else return n*fact(n - 1); //recursion expression
}

int main()
{
    int n;
    printf("Plz enter the num n:\n");
    scanf("%d",&n);
    printf("The fact(%d) = %d.\n",n,fact(n));
    return 0; 
}


