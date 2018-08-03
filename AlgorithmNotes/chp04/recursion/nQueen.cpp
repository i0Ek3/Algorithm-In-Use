// 
// nQueen.cpp
// ianpasm(kno30826@gmail.com)
// 2017-12-10 14:33:20
//
// N Queen:
//  answer based on permutation.
//  
//  set n queens on a n*n international chess plate
//  make n queens not at the same row/line/diagonal,please gives schemes.
//
// Mentality:
//  write row number of all lines
//  then we can get n! permutations
//
 

// Permutation
int cnt = 0;
void generateP(int index)
{
    if (index == n + 1) //recursion borden
    {
        bool flag = true;
        for (int i = 0; i <= n; i++) //traverse any queens
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (abs(i - j) == abs(P[i] - P[j])) //at the same line
                {
                    flag = false; //illegal
                }
            }
        }
        if (flag) cnt++; 
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}


// Backtracking
void generateP(int index)
{
    if (index == n + 1) //recursion borden
    {
        cnt++; //legal
        return;
    }
    for (int x = 0; x <= n; x++)
    {
        if (hashTable[x] == false) //have no queen at line x
        {
            bool flag = true; //represent no conflict with queens before
            for (int pre = 1; pre < index; pre++) 
            {
                if (abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false; //conflict
                    break;
                }
            }
            if (flag) //set queen at x line
            {
                P[index] = x; //make row index queen's equal x
                hashTable[x] = true; //line x was token up
                generateP(index + 1); //tackle line (index + 1) recursionally
                hashTable[x] = false; //recursion done,set line x was free
            }
        }
    }
}
