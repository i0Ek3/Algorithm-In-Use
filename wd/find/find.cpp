// find snippet



#include <iostream>
#define N 50;

int buf[N];


int main()
{

    int begin = 0, end = size;

    while (begin <= end) {
        int mid = (begin + end) / 2;
        int target;
        scanf("%d", &target);
        if (buf[mid] <= traget) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    int ans = end;

    return 0;
}

