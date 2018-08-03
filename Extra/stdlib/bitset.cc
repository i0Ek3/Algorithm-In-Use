// 
// bitset.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-15 16:08:34
// 
 
#include <iostream>
#include <bitset>
#include <string>
using std::string;
using std::bitset;
using std::cout;
using std::cin;
using std::endl;


int main()
{
    int n;
    //declaration, 32 bit, low order is 1, others' 0
    bitset<32> bitvec(1U); 
    //bitset<n> b(u);
    //bitset<n> b(s, pos, m, zero, one);

    //use unsigned initialize bitset
    bitset<13> bitvec1(0xbeef);
    bitset<20> bitvec2(0xbeef);
    bitset<128> bitvec3(~0ULL); // 11...1110...00
                                // |..64..|..64..|

    //initialize bitset from string
    bitset<32> bitvec4("1100");
                      //3210      is index of string
                      //the order of string index is opposite with bitset
    
    string str("11111111100000010001110");
    bitset<32> bitvec5(str, 5, 4); //it shows 1111
    bitset<32> bitvec6(str, str.size() - 4); //it shows 1110

    //operation of bitset
    //all of this operation cannot accept argument follows:
    //b.any();
    //b.all();
    //b.none();
    //b.count();
    //b.size();

    bitvec.flip(0); //reverse first place
    bitvec.set(0, 0); //restoration first place
    
    //fetch value of bitset
    //to_ulong, to_ullong
    unsigned long ulong = bitvec3.to_ulong();
    cout << "ulong = " << ulong << endl;

    //read input
    bitset<16> bits;
    cin >> bits;
    cout << bits << endl;



    return 0;
}
