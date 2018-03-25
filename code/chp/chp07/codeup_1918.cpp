// 
// codeup_1918.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-25 09:09:10
//
// Simple Calculator
// 
// @Problem
// Read includes add,sub,multi,div operation only between postive integers expression,calculate its result.
// Format includes two lines,one is expression and other one is single number 0 in order that end input.Correct to after two place in dicimal.
//
// @Case
// input:  30 / 90 - 26 + 97 - 5 - 6 - 13 / 88 * 6 + 51 / 29 + 79 * 87 + 57 * 92
//         0
// output: 12178.21
//
//
 
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

struct node {
    double num;  //操作数
    char op;  //操作符
    bool flag;  //true表示操作数，false表示操作符
};

string str;
stack<node> s; //操作符栈
queue<node> q; //后缀表达式序列
map<char,int> op;

void toPostfix()
{
    double num;
    node temp;
    for (int i = 0; i < str.length(); )
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag = false;
            while (!s.empty() && op[str[i]] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double Calculate()
{
    double t1,t2;
    node cur,temp;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.flag == true)
        {
            s.push(cur);
        }
        else
        {
            t2 = s.top().num;
            s.pop();
            t1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+')
            {
                temp.num = t1 + t2;
            }
            else if (cur.op == '-')
            {
                temp.num = t1 - t2;
            }
            else if (cur.op == '*')
            {
                temp.num = t1 * t2;
            }
            else
            {
                temp.num = t1 / t2;
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin,str), str != "0")
    {
        for (string::iterator it = str.end(); it != str.begin(); it--)
        {
            if (*it == ' ')
            {
                str.erase(it);
            }
        }
        while (!s.empty())
        {
            s.pop();
        }
        toPostfix();
        printf("%.2f\n",Calculate());
    }
    return 0;
}

