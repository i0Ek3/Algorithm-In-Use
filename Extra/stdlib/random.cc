// 
// random.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-19 15:43:32
// 
 
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void random_engine()
{
    //defined calling operation and returned an random undigned integer
    std::default_random_engine e;
    for (size_t i = 0; i < 10; i++)
    {
        cout << e() << endl;
    } 

    //different with c lib function rand
    cout << "min: " << e.min() << "max: " << e.max() << endl;
}

void random_distribution()
{
    //generate the uniform distribution numbers between 0 and 9
    uniform_int_distribution<unsigned> u(0, 9);
    std::default_random_engine e;
    for (size_t i = 0; i < 10; i++)
    {
        cout << u(e) << " ";
    }
}

vector<unsigned> randVec()
{
    //holds different status between default_random_engine and uniform_int_distribution 
    static std::default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
    {
        ret.push_back(u(e));
    }
    return ret;
}

void seed()
{
    //same seed
    std::default_random_engine e1;
    //std::default_random_engine e1(time(0)); //random seed slightly
    std::default_random_engine e2(2147483646);

    //different seed
    std::default_random_engine e3;
    e3.seed(32767);
    std::default_random_engine e4(32767);

    for (size_t i = 0; i != 100; ++i)
    {
        if (e1() == e2())
        {
            cout << "unseeded match at iteration: " << i << endl;
        }
        if (e3() != e4())
        {
            cout << "seeded differs at iteration: " << i << endl;
        }
    }
}

void random_double()
{
    std::default_random_engine e;
    uniform_real_distribution<double> u(0, 1);
    for (size_t i = 0; i < 10; ++i)
    {
        cout << u(e) << " ";
    }
}

void normal_dist()
{
    std::default_random_engine e;
    normal_distribution<> n(4, 1.5);
    vector<unsigned> vals(9);
    for (size_t i = 0; i != 200; ++i)
    {
        unsigned v = lround(n(e));
        if (v < vals.size())
        {
            ++vals[v];
        }
    }
    for (size_t j = 0; j != vals.size(); ++j)
    {
        cout << j << ": " << string(vals[j], '*') << endl;
    }
}

bool game()
{
    string resp;
    std::default_random_engine e;
    bernoulli_distribution b;
    
    bool first;
    while (cin >> resp && resp[0] == 'y')
    {
        first = b(e);
        cout << (first ? "We go first" : "You get go first") << endl;
        cout << ((game()) ? "sorry, you lost" : "congrats, you won") << endl;
        //cout << "play again? Enter 'yes' or 'no' to continue: " << endl;
    }
    return first;
}

int main()
{
    //random_engine();
    //random_distribution();
    //seed();
    //random_double();
    //normal_dist();
    //bool first;
    game();

    return 0;
}


