// 
// tuple.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-15 15:40:22
// 
 
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::tuple;
using std::cout;
using std::endl;


int main()
{
    tuple<size_t, size_t, size_t> threeD{1, 2, 3};

    //explicit
    tuple<string, vector<double>, int, list<int>> someVal("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5})

    //item is a tuple type, tuple<const char*, int, double>
    auto item = make_tuple("xxxdsxx", 4, 3.33);

    //through get<> template to visit tuple's members
    //return first and second member
    auto book = get<0>(item);
    auto cnt = get<1>(item);

    //if you don't know the tuple's type details exactly, maybe you should use assiant template to ensure that.
    typedef decltype(item) trans;
    size_t sz = std::tuple_size<trans>::value;
    std::tuple_element<l, trans>::type cnt = get<1>(item);

    //you just can compare the same type and numbers of tuple
    tuple<string, string> a("1", "3");
    tuple<size_t, size_t> b(1, 2);
    tuple<size_t, size_t> c(3, 4);
    bool ret1 = (b == c); //right, same type and numbers
    bool ret2 = (a == b); //error, different type

    //define a tuple which includes three int and assigned value with 10, 20, 30 respectively 
    tuple<int, int, int> ti{10, 20, 30};  
    tuple<string, vector<string>, pair<string, int>> t;



    return 0;
}

