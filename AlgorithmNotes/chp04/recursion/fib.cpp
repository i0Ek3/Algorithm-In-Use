// 
// fib.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-09 09:00:38
// 
 
#include <cstdio>

int fib(int n)
{
    if (1 == n) return 0;
    else if (2 == n) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    printf("Plz enter a num n:\n");
    scanf("%d",&n);
    printf("The fib(%d) = %d.\n",n,fib(n));
    return 0;
}

