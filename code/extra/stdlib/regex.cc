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
using std::string;
using std::regex;
using std::sregex_iterator;
using std::smatch;
using std::cmatch;
using std::endl;
using std::cout;
using std::cin;
//using std::regex_constants::format_no_copy;
using namespace std::regex_constants;


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
    catch (std::regex_error e)
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

bool valid(const smatch& m)
{
    if (m[1].matched)
    {
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    }
    else
    {
        return !m[3].matched && m[4].str() == m[6].str();
    }
}

void checkphonenumber()
{
    //To match America phone number type like this: 
    //  123 123 1234 
    //  123-123-1234
    //
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    while (getline(cin, s))
    {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        {
            if (valid(*it))
            {
                cout << "valid: " << it->str() << endl;
            }
            else
            {
                cout << "not valid: " << it->str() << endl;
            }
        }
    }
}

void replacere()
{
    string fmt = "$2.$5.$7";
    string s;
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    
    while (getline(cin, s))
    {
        cout << "The original number is : " << s << endl;
        //cout << "After replaced: " << regex_replace(s, r, fmt) << endl;
        cout << regex_replace(s, r, fmt, format_no_copy) << endl;
    }
}

int main()
{
    //match_alpha();
    cout << "=====================" << endl;
    //icase();
    cout << "=====================" << endl;
    //try_exception();
    cout << "=====================" << endl;
    //retype();

    cout << "=====================" << endl;

    //match_alpha2();
    //checkphonenumber();
    
    replacere();
    return 0;
}


