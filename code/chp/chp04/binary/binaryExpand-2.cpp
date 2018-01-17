 // 
 // binaryExpand-2.cpp
 // ianpasm(kno30826@gmail.com)
 // 2018-01-17 08:55:56
 // 

//binaryExpand instance of fill water question.

#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);
const double esp = 1e-5;

double f(double R,double h)
{
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double S1 = alpha * R * R / 2 - L * (R - h) / 2;
    double S2 = PI * R * R / 2;
    return S1 / S2;
}

double solve(double R,double r)
{
    double left = 0,right = R,mid;
    while (right - left > mid)
    {
        mid = (left + right) / 2;
        if (f(R,mid) > r)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main()
{
    double R,r;
    printf("Please input two value R & r:\n");
    scanf("%lf%lf",&R,&r);
    printf("mid = %.4f\n",solve(R,r));

    return 0;
}


