// 
// pat_b1020-v2.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-11 13:02:42
// 
 
#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake {
    double store;
    double sell;
    double price;
}cake[100];

bool cmp(mooncake a,mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n;
    double d,profit = 0;
    printf("Plz enter mooncakes types number n and needs d:\n");
    scanf("%d %lf",&n,&d);
    printf("Plz enter %d types mooncakes' store:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&cake[i].store);
    }
    printf("Plz enter %d types mooncakes' sell:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake,cake + n,cmp);
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= d)
        {
            d -= cake[i].store;
            profit += cake[i].sell;
        }
        else
        {
            profit += cake[i].price * d;
            break;
        }
    }
    printf("The biggest profit is:\n");
    printf("%.2f",profit);

    return 0;
}


