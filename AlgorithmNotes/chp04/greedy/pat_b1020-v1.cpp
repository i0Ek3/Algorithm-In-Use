// 
// pat_b1020.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-11 10:42:03
// 
// Greeedy Algorithm Case
// 
// Mooncake
//   type         A   B   C
//   stock       18  15  10
//   totalPrice  75  72  45
//   need            20
//   profit        94.5
//
// input
//   n  d        //mooncake type nums and need nums
//   s1 s2 s3    //stock nums
//   tp1 tp2 tp3 //totalPrice
// output
//   maxprofit   //profit
 
#include <cstdio>
#include <cstring>

const int maxn = 10;
double stock[maxn],totalPrice[maxn],singlePrice[maxn];
double profit;

#if 0
int singlePrice(double *singlePrice,int n)
{
    double a,b,c,temp;
    a = singlePrice[0];
    b = singlePrice[2];
    for (int i = 0; i < n; i++)
    {
        temp = ((a > singlePrice[1]) ? a : singlePrice[1]);
        c = (b > temp ? b : temp);
    }
    return i;
}
#endif


int main()
{
    int n;
    double a,b,c,d,temp;
    printf("Plz enter mooncakes type numbers n and needs d:\n");
    scanf("%d %lf",&n,&d);
    printf("Plz enter %d type mooncakes' stock:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&stock[i]);
    }

    //find out the max singlePrice.
    printf("Plz enter %d types mooncakes' totalPrice:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&totalPrice[i]);
        singlePrice[i] = int(totalPrice[i]) / int(stock[i]);
    }

    a = singlePrice[0];
    b = singlePrice[2];
    temp = ((a > singlePrice[1]) ? a : singlePrice[1]);
    c = (b > temp ? b : temp);

    //should find out the max singlePrice item then compare that stock with d
    for (int i = 0; i < n; i++)
    {
        if (stock[i] < d)
        {
            profit = totalPrice[i] + (d - stock[i]) * a;
        }
        else
        {
            profit = totalPrice[i];
        }
    }
    printf("The best scheme's profit is:\n");
    printf("%.2f",profit);

    return 0;
}

