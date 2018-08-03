// 
// priority_queue.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-24 09:43:55
//  
//  If there is a huge struct you should use reference & to improve efficent,
//  and add const & front of parameters.
//
//
 
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::priority_queue;

struct fruit {
    string name;
    double price;
    friend bool operator < (fruit f1,fruit f2)
    {
        return f1.price < f2.price;
    }
}f1,f2,f3;

struct cmp {
    bool operator () (fruit f1,fruit f2)
    {
        return f1.price > f2.price;
    }
};

void base_func()
{
    priority_queue<int> pq;
    if (pq.empty() == true)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    pq.push(5);
    pq.push(4);
    if (pq.empty() == true)
    {
        cout << "Opps!" << endl;
    }
    else
    {
        cout << "The top element is: \t" << pq.top()
             << "\nAnd the size of pq is: \t" << pq.size()
             << endl;
    }
    pq.pop();
    cout << "Now the size of pq is: \t" << pq.size()
         << "\nAnd the top element is: \t" << pq.top()
         << endl;
}

void priority_base_type()
{
    priority_queue<int, vector<int>, std::greater<int> > q;
    q.push(3);
    q.push(5);
    q.push(2);
    
    cout << q.top() << "\t"
         << q.size()
         << endl;
}

// Please remember overload '>' will occurs impile error,you must use '<' to express related expression.
// Like this: f1 > f2 equal f2 < f1
//
void priority_struct()
{
    priority_queue<fruit> q;
    f1.name = "apple";
    f1.price = 5.0;
    f2.name = "banana";
    f2.price = 3.4;
    f3.name = "pear";
    f3.price = 4.3;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;    
}

void priority_overload_cmp()
{
    priority_queue<fruit,vector<fruit>,cmp> q;
    f1.name = "apple";
    f1.price = 5.0;
    f2.name = "banana";
    f2.price = 3.4;
    f3.name = "pear";
    f3.price = 4.3;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;    
}

int main()
{
    //base_func();
    //priority_base_type();
    //priority_struct();
    priority_overload_cmp();
    return 0;
}

