// 
// regex.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-16 15:19:07
//
// @regex libarary
//  The regular expression language we used which based on ECMAScript.
//
// @Other regular expression error types please visit C++ Primer 5th on page 649 in Chinese version. 
//
// @Note
//  We should know that a regular expression program compiled on runtime not complie time.
//  As we all know it's complied slowly, so we should try to avoid create an unnecessary regular expression as possible.
//  If you need this certainly please create it out of any loop.
//
//
//
 
#include <iostream>
#include <regex>
#include <string>
using namespace std;


void match_alpha()
{
    string pattern("[^c]ei"); //search pattern
    
    //includes whole words of pattern support
    //[[:alpha:]]* match zero or more alpha
    //means match words like this:   ******[^c]ei********
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
    regex r(pattern); //construct regex
    smatch results; //save search results
    string test_str = "receipt freind theif receive"; //search case
     
    if (regex_search(test_str, results, r))
        cout << results.str() << endl;
}


void match_alpha2()
{
    string pattern("[^c]ei"); //search pattern
    
    //includes whole words of pattern support
    //[[:alpha:]]* match zero or more alpha
    //means match words like this:   ******[^c]ei********
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
    regex r(pattern, regex::icase); //construct regex
    
    string file = "receipt freind theif receive"; //search case
    //multi calling regex_search to find all matches on the file
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
    {
        cout << it->str() << endl;
    }
}

void icase()
{
    //match ignore case files' expand name
    //. match any character, so we need use \ to remove it's special meaning
    //and we still use another \ to change last \ meaning
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string filename;
    while (cin >> filename)
    {
        if (regex_search(filename, results, r))
        {
            cout << results.str() << endl;
        }
    }
}

void try_exception()
{
    try {
        //if there is no error then result will show you nothing
        //if there lack of a ] then result will show you error message
        regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    } 
    catch (regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
}

void retype()
{
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    //smatch results; //smatch is not matched with input sequence so we should use cmatch replace smatch
    cmatch results;
    if (regex_search("file.cc", results, r))
    {
        cout << results.str() << endl;
    }
}

void reiterator()
{
    
}


int main()
{
    match_alpha();
    cout << "=====================" << endl;
    //icase();
    cout << "=====================" << endl;
    try_exception();
    cout << "=====================" << endl;
    retype();

    cout << "=====================" << endl;

    match_alpha2();

    return 0;
}


