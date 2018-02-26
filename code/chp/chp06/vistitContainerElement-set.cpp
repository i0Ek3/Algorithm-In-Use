// 
// vistitContainerElement-set.cpp
// ianpasm(kno30826@gmail.com)
// 2018-02-26 09:43:20
// 

#include <cstdio>
#include <iostream>
#include <set>
#include <iterator>
using std::cout;
using std::endl;
using std::set;
using std::iterator;

int main()
{
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        printf("%d ",*it);
    }

    return 0;
}
