// 
// huffman.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-23 10:18:06
//
// @Huffman & Huffman Coding
//  
// @Question -- Combine fruit
//  
//
//
 
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<long long, std::vector<long long>, std::greater<long long> > q;

int main()
{
    int n;
    long long temp, x, y, ans = 0;
    printf("Please input a number at least 3: \n");
    scanf("%d", &n); //node numbers
    
    printf("Input %d weithts: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        q.push(temp);
    }

    while (q.size() > 1)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }

    printf("The sum of node is %lld.\n", ans);
    return 0;
}


