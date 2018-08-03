 // 
 // instances.cpp
 // ianpasm(kno30826@gmail.com)
 // 2017-12-19 20:35:34
 //
 //QUESTION:
 // How to judge below two functions(lower_bound() & upper_bound()) queried successful?
 //


//1 return the first number's index which is >= x 

int lower_bound(int A[],int left,int right,int x)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] >= x)
        {
            right = mid;
        }
        else 
        {
            left = mid + 1;
        }
    }
    return left;
}


//2 return the first number's index which is > x

int upper_bound(int A[],int left,int right,int x)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }   
    } 
    return left;
}


//3 the model for find the first number's index in order list

int solve1(int left,int right)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (condition)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}


//4 same above 3
//(left,right]

int solve2(int left,int right)
{
    int mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (condition)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}
