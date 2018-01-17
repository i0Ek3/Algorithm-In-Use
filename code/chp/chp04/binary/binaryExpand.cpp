 // 
 // binaryExpand.cpp
 // ianpasm(kno30826@gmail.com)
 // 2018-01-17 08:15:24
 // 

// 01
// binaryExpand to calculate sqrt(2) approximate value.
// instances like under this:

const double esp = 1e-5;
double f(double x)
{
    return x * x;
}

double calSqrt()
{
    double left = 1,right = 2,mid;
    mid = (left + right) / 2;
    while ((right - left) > esp)
    {
        if (f(mid) > 2)
            right = mid;
        else
            left = mid;
    }
    return mid;
}


// 02
// This instance is special based on above instance
// and it mean to calculate the value of equation f(x)=0 on the section [L,R]

const double esp = 1e-5;
double f(double x)
{
    return x * x - 2 * x; //change your equation
}

double solve(double L,double R)
{
    double left = L,right = R,mid;
    mid = (right + left) / 2;
    while (right - left > esp)
    {
        if (f(mid) > 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}
