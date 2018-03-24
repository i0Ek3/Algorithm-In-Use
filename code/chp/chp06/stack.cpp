// 
// stack.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-24 10:27:43
// 
 
#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::endl;

int main()
{
    stack<int> st;
    if (st.empty() == true )
    {
        cout << "Now this stack is empty,please add something;" << endl;
    }
    else
    {
        cout << "The top element of st is: \t" << st.top()
             << "\nThe size of st is: \t" << st.size()
             << endl;
    }
    cout << "Adding...\n";
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout << "The top element of st is: \t" << st.top()
         << "\nThe size of st is: \t" << st.size()
         << endl;

    return 0;
}


