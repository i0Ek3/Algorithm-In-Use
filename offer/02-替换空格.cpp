#include <iostream>
#include <string>
using namespace std;

string replace(string  str) {
    string s;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            s += "%20";
            continue;
        }
        s += str[i];
    }
    return s;
}

